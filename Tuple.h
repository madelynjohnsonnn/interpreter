//
//  Tuple.h
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Tuple_h
#define Tuple_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "Parameter.h"
using namespace std;

class Tuple {
public:
//    Tuple(string n);
    Tuple();
    void AddToTuple(Parameter* p);
    string toString();
    
    vector <Parameter*> values;
private:
    bool operator< (const Tuple & other) const {
        return (this->values < other.values);
    }
//    string name;
};

#endif /* Tuple_h */
