//
//  Interpreter.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram* dp){
    database = new Database();
    datalog = dp;
}

Interpreter::~Interpreter() {
    delete database;
}

void Interpreter::Run() {
    //SCHEME
    for (vector<Predicate*>::iterator it = datalog->schemes.begin(); it != datalog->schemes.end(); it++) {
        Header header = Header();
        for (vector<Parameter*>::iterator it2 = (*it)->parameters.begin(); it2 != (*it)->parameters.end(); it2++) {
            header.AddAttribute((*it2));
        }
        Relation* r = new Relation(Relation((*it)->name, header));
        database->addRelation((*it)->name, r);
    }
    
    //FACTS
    for (vector<Predicate*>::iterator it = datalog->facts.begin(); it != datalog->facts.end(); it++) {
        Tuple tuple = Tuple();
        for (vector<Parameter*>::iterator it2 = (*it)->parameters.begin(); it2 != (*it)->parameters.end(); it2++) {
            tuple.AddToTuple((*it2));
        }
        
        for (map<string, Relation*>::iterator it3 = database->relations.begin(); it3 != database->relations.end(); it3++) {
            if ((*it3).first == (*it)->GetName()) {
                Relation* rel = database->relations[(*it)->name];
                rel->AddTuple(tuple);
            }
        }
    }
    
    //EVALUATING RULES
    unsigned long startTupleNum = CountTuples();
    unsigned long endTupleNum = startTupleNum;
    bool flag = true;
    unsigned int numPasses = 0;
    string out = "Rule Evaluation\n";;
    
    do {
        out += EvaluateRules();
        numPasses++;
        endTupleNum = CountTuples();
        if (endTupleNum == startTupleNum) {
            flag = false;
        }
        else {
            startTupleNum = endTupleNum;
        }
    } while (flag == true);
    
    out += "\nSchemes populated after " + to_string(numPasses) + " passes through the Rules.\n\n";
    
    //EVALUATING QUERIES
    out += EvaluateQueries();
    
    cout << out;
}

unsigned long Interpreter::CountTuples() {
    unsigned long returnVal = 0;
    for (map<string, Relation*>::iterator it = database->relations.begin(); it != database->relations.end(); it++) {
        returnVal += (*it).second->tuples.size();
    }
    return returnVal;
}

string Interpreter::EvaluateRules() {
    string out = "";
    Relation* finalRelation;
    
    //Evaluate the predicates on the right-hand side of the rule:
    for (vector<Rule*>::iterator it = datalog->rules.begin(); it != datalog->rules.end(); it++) {
        out += (*it)->toString();
        
        vector<Relation> ruleBodyPredicates;
        for (vector<Predicate*>::iterator it2 = (*it)->bodyPredicates.begin(); it2 != (*it)->bodyPredicates.end(); it2++) {
            Relation r = EvaluatePredicate((*it2));
            ruleBodyPredicates.push_back(r);
        }
        
        //for each new relation inside of vector<Predicate*> ruleBodyPredicates, join together to create finalRelation
        finalRelation = &(ruleBodyPredicates.at(0));
        
        for (unsigned int i = 1; i < ruleBodyPredicates.size(); i++) {
            finalRelation = finalRelation->NaturalJoin(&(ruleBodyPredicates.at(i)));
        }
        
        //project the columns of head predicate on finalRelation to get finalRelation2
        vector<int> pos;
        unsigned int i = 0;
        for (vector<Parameter*>::iterator it3 = (*it)->headPredicate->parameters.begin(); it3 != (*it)->headPredicate->parameters.end(); it3++) {
            i = 0;
            for (vector<Parameter*>::iterator it2 = finalRelation->header.attributes.begin(); it2 != finalRelation->header.attributes.end(); it2++) {
                if ((*it2)->GetName() == (*it3)->GetName()) {
                    pos.push_back(i);
                }
                i++;
            }
        }
        finalRelation->project(pos);
        
        //headPred = the relation in the database that matches the head predicate
        Relation ruleHeadPredicate = EvaluatePredicate((*it)->headPredicate);
        
        //rename each attribute in finalRelation2 to match headPred, creating finalRelation3
        vector<string> ruleHeadPredicateHeaderVals;
        for (vector<Parameter*>::iterator it3 = ruleHeadPredicate.header.attributes.begin(); it3 != ruleHeadPredicate.header.attributes.end(); it3++) {
            ruleHeadPredicateHeaderVals.push_back((*it3)->GetName());
        }
        finalRelation->renameHeader(ruleHeadPredicateHeaderVals);
        finalRelation->renameName(ruleHeadPredicate);
        //finalRelation3 is now union compatible with headPred
        
        //union finalRelation with headPred
        Header headVals;
        for (vector<Predicate*>::iterator it2 = datalog->schemes.begin(); it2 != datalog->schemes.end(); it2++) {
            if ((*it2)->GetName() == ruleHeadPredicate.name) {
                headVals.attributes = ((*it2)->parameters);
            }
        }
        
        out += ruleHeadPredicate.Unionize(*(finalRelation), headVals);
        
        //update headPred in database with new relation
        database->addRelation(ruleHeadPredicate.name, &(ruleHeadPredicate));
    }
    return out;
}

string Interpreter::EvaluateQueries() {
    string out = "Query Evaluation\n";
    for (vector<Predicate*>::iterator it2 = datalog->queries.begin(); it2 != datalog->queries.end(); it2++) {
        Relation r = EvaluatePredicate((*it2));
//        TestSet();
        
        //PRINT OUT RESULTS FOR LAB3
        out += (*it2)->toString2() + " ";
        unsigned int size = 0;
        for (set<Tuple>::iterator it = r.tuples.begin(); it != r.tuples.end(); it++) {
            size++;
        }
        if (size == 0) {
            out += "No\n";
        }
        else {
            out += "Yes(" + to_string(size) + ")\n";
        }
        
        bool allConst = true;
        for (vector <Parameter*>::iterator it3 = (*it2)->parameters.begin(); it3 != (*it2)->parameters.end(); it3++) {
            if ((*it3)->isConstant() != true) {
                allConst = false;
                break;
            }
        }
        
        if (!allConst) {
            out += r.toString();
        }
    }
    return out;
}

Relation Interpreter::EvaluatePredicate(Predicate* p) {
//    select for each constant in the query ‘q’
//    select for each pair of matching variables in ‘q’
//    project using the positions of the variables in ‘q’
//    rename to match the names of variables in ‘q’
//    print the resulting relation
    Relation rel = *(database->relations[p->name]);
    map<int,string> variableMap;
    unsigned int i = 0;
    unsigned int j = 0;
    
    //SELECT
    for (vector <Parameter*>::iterator it = p->parameters.begin(); it != p->parameters.end(); it++) {
        if ((*it)->isConstant() == true) { //STRING
            rel = *(rel.select1(&rel, i, (*it)->GetName()));
        }
        else { //is a variable
            bool haveSeen = false;
            for (map<int,string>::iterator it3 = variableMap.begin(); it3 != variableMap.end(); it3++) {
                if ((it3)->second == (*it)->GetName()) {
                    haveSeen = true;
                    j = (*it3).first;
                    break;
                }
            }
            
            if (!haveSeen) {
                variableMap.insert(pair<int, string>(i, (*it)->GetName()));
            }
            else {
                rel = *(rel.select2(&rel, i, j));
            }
        }
        i++;
    }
    
    //PROJECT AND RENAME
    vector<int> pos;
    vector<string> newHeaderVals;
    for (map<int, string>::iterator it = variableMap.begin(); it != variableMap.end(); it++) {
        pos.push_back((*it).first);
        newHeaderVals.push_back((*it).second);
    }
    rel.project(pos);
//    rel = *(rel.rename(&rel, newHeaderVals));
    rel.renameHeader(newHeaderVals);
    
    return rel;
}

//void Interpreter::TestSet() {
//
//    Parameter* p1 = new Parameter("a", STRING);
//    Parameter* p2 = new Parameter("b", STRING);
//    Parameter* p3 = new Parameter("c", STRING);
//    Parameter* p4 = new Parameter("d", STRING);
//    Parameter* p5 = new Parameter("e", STRING);
//    Parameter* p6 = new Parameter("f", STRING);
//    Parameter* p7 = new Parameter("g", STRING);
//    Parameter* p8 = new Parameter("h", STRING);
//
//
//    Tuple t1 = Tuple();
//    t1.AddToTuple(p1);
//    t1.AddToTuple(p2);
//
//    Tuple t2 = Tuple();
//    t2.AddToTuple(p3);
//    t2.AddToTuple(p4);
//
//    Tuple t3 = Tuple();
//    t3.AddToTuple(p5);
//    t3.AddToTuple(p6);
//
//    Tuple t4 =  Tuple();
//    t4.AddToTuple(p5);
//    t4.AddToTuple(p6);
//
//    Tuple t5 =  Tuple();
//    t5.AddToTuple(p8);
//    t5.AddToTuple(p7);
//
//    set<Tuple> s;
//    s.insert(t5);
//    s.insert(t3);
//    s.insert(t4);
//    s.insert(t2);
//    s.insert(t1);
//
//    if ((t2) < (t1)) {
//        cout << "hi";
//    }
//}
