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
//#include "Interpreter.h"
using namespace std;

//DOESN'T KNOW DATALOGPROGRAM CLASSES EXIST, ONLY INTERPRETER
class Database {
public:
    Database() {}
    void addRelation(string name, Relation* relation) {
        relations.insert(pair<string, Relation*>(name, relation));
    }
    void toString();
    map<string, Relation*> relations;
//    int GetSize();
private:
    
};

#endif /* Database_h */
