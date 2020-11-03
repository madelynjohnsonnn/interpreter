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
        for (vector<Parameter*>::iterator it2 = (*it)->parameters.begin(); it2 != (*it)->parameters.end(); it2++) {
            header.AddAttribute((*it2));
        }
        Relation* r = new Relation(Relation((*it)->name, header));
        database->addRelation((*it)->name, r);
        
        //FACTS
        for (vector<Predicate*>::iterator it3 = datalog->facts.begin(); it3 != datalog->facts.end(); it3++) {
            Tuple* tuple = new Tuple();
            for (vector<Parameter*>::iterator it6 = (*it3)->parameters.begin(); it6 != (*it3)->parameters.end(); it6++) {
                tuple->AddToTuple((*it6));
            }
            
            for (map<string, Relation*>::iterator it5 = database->relations.begin(); it5 != database->relations.end(); it5++) {
                if ((*it5).first == (*it3)->GetName()) {
                    r->AddTuple(tuple);
                }
            }
        }
    }
    EvaluateQueries();
}

void Interpreter::EvaluateQueries() {
    for (vector<Predicate*>::iterator it2 = datalog->queries.begin(); it2 != datalog->queries.end(); it2++) {
        Relation r = EvaluatePredicate((*it2));
        (*it2)->toString2();
        string out = r.toString(); //PRINT OUT RESULTS FOR LAB3
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

Relation* Interpreter::StoreRelation(string n, Header h) {
    storedRelation = new Relation(n,h);
    return storedRelation;
}

Relation* Interpreter::GetRelation() {
    return storedRelation;
}
