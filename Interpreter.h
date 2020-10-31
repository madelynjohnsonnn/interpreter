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

//MANAGES DATABASE, CONNECTS BETWEEN DATALOGPROGRAM AND DATABASE
class Interpreter {
public:
    Interpreter(DatalogProgram* dp);
    void Run();
private:
    DatalogProgram* datalog;
    Database* database;
};

#endif /* Interpreter_h */
