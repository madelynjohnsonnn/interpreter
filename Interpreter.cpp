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

//Interpreter::~Interpreter() {
//    delete database;
//}

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
    for (vector<Predicate*>::iterator it3 = datalog->facts.begin(); it3 != datalog->facts.end(); it3++) {
        Tuple tuple = Tuple();
        for (vector<Parameter*>::iterator it6 = (*it3)->parameters.begin(); it6 != (*it3)->parameters.end(); it6++) {
            tuple.AddToTuple((*it6));
        }
        
        for (map<string, Relation*>::iterator it5 = database->relations.begin(); it5 != database->relations.end(); it5++) {
            if ((*it5).first == (*it3)->GetName()) {
                Relation* rel = database->relations[(*it3)->name];
                rel->AddTuple(tuple);
            }
        }
    }
    //EvaluateRules();
    EvaluateQueries();
    EvaluateRules();
}

void Interpreter::EvaluateQueries() {
    for (vector<Predicate*>::iterator it2 = datalog->queries.begin(); it2 != datalog->queries.end(); it2++) {
        Relation r = EvaluatePredicate((*it2));
//        TestSet();
        
        //PRINT OUT RESULTS FOR LAB3
        
        string out = "Query Evaluation\n";
        out = (*it2)->toString2() + " ";
        int size = 0;
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
        cout << out;
    }
}

Relation Interpreter::EvaluatePredicate(Predicate* p) {
//    select for each constant in the query ‘q’
//    select for each pair of matching variables in ‘q’
//    project using the positions of the variables in ‘q’
//    rename to match the names of variables in ‘q’
//    print the resulting relation
    Relation rel = *(database->relations[p->name]);
    map<int,string> variableMap;
    int i = 0;
    int j = 0;
    
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
    rel = *(rel.project(&rel, pos));
    rel = *(rel.rename(&rel, newHeaderVals));
    
    return rel;
}

void Interpreter::EvaluateRules() {
    
//    for (vector<Rule*>::iterator it2 = datalog->rules.begin(); it2 != datalog->rules.end(); it2++) {
//        Relation* r = r->NaturalJoin(*it2);
//    }
    
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
