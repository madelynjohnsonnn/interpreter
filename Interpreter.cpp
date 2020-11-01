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
    //make relation for each scheme predicate. take each predicate from scheme vector and look at it's name/header, make a relation with name and header (empty tuples) put into database map <string,relation>
    //for each fact in datalog vector, look at name and look up in database what relation corresponds to the fact (what table to put row in) and insert tuple into relation
    
    //SCHEME
    vector<Predicate*>::iterator it;
    for (it = datalog->schemes.begin(); it != datalog->schemes.end(); it++) {
        vector<Parameter*>::iterator it2;
        for (it2 = (*it)->parameters.begin(); it2 != (*it)->parameters.end(); it2++) {
            header.AddAttribute((*it2));
        }
        Relation* relation = new Relation(Relation((*it)->name, header));
        database->addRelation((*it)->name, relation);
        
        //FACTS
        vector<Predicate*>::iterator it3;
        for (it3 = datalog->facts.begin(); it3 != datalog->facts.end(); it3++) {
            
            /*
            //DOMAINS
            Tuple* tuple = new Tuple();
            set<string>::iterator it4;
            for (it4 = datalog->domains.begin(); it4 != datalog->domains.end(); it4++) {
                tuple->AddToTuple((*it4));
            }
            */
            
            Tuple* tuple = new Tuple();
            vector<Parameter*>::iterator it6;
            for (it6 = (*it3)->parameters.begin(); it6 != (*it3)->parameters.end(); it6++) {
                tuple->AddToTuple((*it6));
            }
            
            map<string, Relation*>::iterator it5;
            for (it5 = database->relations.begin(); it5 != database->relations.end(); it5++) { //TODO ERROR
                if ((*it5).first == (*it3)->GetName()) {
                    relation->AddTuple(tuple);
                }
            }
        }
//        Relation* relation1 = new Relation(Relation((*it)->name, header));
//        database->addRelation((*it)->name, relation1);
    }
    
}
