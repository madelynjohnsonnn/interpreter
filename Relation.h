//
//  Relation.h
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include <stdio.h>
#include <iostream>
#include <set>
#include "Tuple.h"
#include "Header.h"
using namespace std;

class Relation {
public:
    Relation(string name, Header* header);
    void AddTuple(Tuple* t);
    void toString();
    void select(int index, string value);
    void select(int index, int index2);
    void project(vector<int> pos);
    
private:
    set <Tuple*> tuples; //coming from facts
    string name;
    Header* header;
};

#endif /* Relation_h */
