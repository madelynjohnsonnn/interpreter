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
#include <string>
#include <vector>
#include "Tuple.h"
#include "Header.h"
using namespace std;

class Relation {
public:
    Relation(string name, Header header);
    Relation() {
        name = "";
    }
    void AddTuple(Tuple t);
//    void SetHeader(Relation* oldRel, Relation* newRel);
//    void SetName(Relation* oldRel, Relation* newRel);
    Header GetHeader(Relation* rel);
//    string GetName(Relation* rel);
    string toString();
    Relation* select1(Relation* r, int index, string value);
    Relation* select2(Relation* r, int index, int index2);
    Relation* project(Relation* r, vector<int> pos);
    Relation* rename(Relation* r, vector<string> newHeader);
    void Unionize(Tuple t); //relational operator
    Relation* NaturalJoin(Relation* r); //relational operator
    Header CombineHeaders(Relation* r1, Relation* r2);
    Tuple GetTupleAtIndex(int index);
    Relation* Copy();
    vector<Tuple> projectTuples(vector<int> pos);
    
//    bool IsJoinable(Tuple t1, Tuple t2);
    
    string name;
    Header header;
    set<Tuple> tuples; //coming from facts
private:
    
};

#endif /* Relation_h */
