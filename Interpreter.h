//
//  Interpreter.h
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Interpreter_h
#define Interpreter_h

#include <stdio.h>
#include <vector>
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"
#include "PlainParameter.h"

//MANAGES DATABASE, CONNECTS BETWEEN DATALOGPROGRAM AND DATABASE
class Interpreter {
public:
    Interpreter(DatalogProgram* dp);
//    ~Interpreter();
    void Run();
    Relation EvaluatePredicate(Predicate* p);
    void EvaluateQueries();
    Relation* StoreRelation(string n, Header h);
    Relation* GetRelation();
private:
    DatalogProgram* datalog;
    Database* database;
    Header header;
    Relation* storedRelation; //the relation that is passed into the Relation class methods. No tuples are in it, just the name and header values.
    vector<string> variables;
};

#endif /* Interpreter_h */
