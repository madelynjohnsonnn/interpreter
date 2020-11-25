//
//  Database.hpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Database_h
#define Database_h

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <list>
#include "Relation.h"
//#include "Header.h"
//#include "Interpreter.h"
using namespace std;

//DOESN'T KNOW DATALOGPROGRAM CLASSES EXIST, ONLY INTERPRETER
class Database {
public:
    Database() {}
    void addRelation(string name, Relation* relation) {
        for (map<string,Relation*>::iterator it = this->relations.begin(); it != this->relations.end(); it++) {
            if ((*it).first == name) {
                (*it).second->header = relation->header;
                (*it).second->tuples = relation->tuples;
                return;
            }
        }
        
        relations.insert(pair<string, Relation*>(name, relation));
    }
    void toString();
    map<string, Relation*> relations;
//    int GetSize();
private:
    
};

#endif /* Database_h */



//        for (map<string,Relation*>::iterator it = this->relations.begin(); it != this->relations.end(); it++) {
//            for (set<Tuple>::iterator databaseTupleit = (*it).second->tuples.begin(); databaseTupleit != (*it).second->tuples.end(); databaseTupleit++) { //NOW I AM GOING THROUGH DATABASE TUPLES
//                for (set<Tuple>::iterator relationTupleit = relation->tuples.begin(); relationTupleit != relation->tuples.end(); relationTupleit++) {
//
//                }
//            }
//        }
