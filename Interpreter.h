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
#include "Parameter.h"

//MANAGES DATABASE, CONNECTS BETWEEN DATALOGPROGRAM AND DATABASE
class Interpreter {
public:
    Interpreter(DatalogProgram* dp);
    //~Interpreter();
    void Run();
    Relation EvaluatePredicate(Predicate* p);
    void EvaluateQueries();
    void EvaluateRules();
private:
    DatalogProgram* datalog;
    Database* database;
    //void TestSet();
};

#endif /* Interpreter_h */
