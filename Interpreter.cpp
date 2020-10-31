//
//  Interpreter.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram* dp){
    datalog = dp;
}

void Interpreter::Run() {
    //make relation for each scheme predicate. take each predicate from scheme vector and look at it's name/header, make a relation with name and header (empty tuples) put into database map <string,relation>
    //scheme
    vector<Predicate*>::iterator it;
    for (it = datalog->schemes.begin(); it != datalog->schemes.end(); it++) {
        Header* header = nullptr;
        vector<Parameter*>::iterator it2;
        for (it2 = (*it)->parameters.begin(); it2 != (*it)->parameters.end(); it2++) {
            header->AddAttribute(*it2);
        }
        Relation* relation = new Relation(Relation((*it)->name, header));
        
        map<string, Relation>::iterator it3;
        for (it = datalog->facts.begin(); it != datalog->facts.end(); it++) {
            for (it3 = database->relations.begin(); it3 != database->relations.end(); it3++) {
                if ((*it3).first == (*it)->GetName()) {
                    Tuple* tuple = new Tuple((*it)->GetName());
                    relation->AddTuple(tuple);
                }
            }
        }
        
        database->addRelation((*it)->name, Relation(Relation((*it)->name, header)));
    }
    //for each fact in datalog vector, look at name and look up in database what relation corresponds to the fact (what table to put row in) and insert tuple into relation
    //facts
    
    
    
}
