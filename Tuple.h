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
    string toString(vector<Parameter*> header);
    bool operator< (const Tuple & other) const {
//        vector<Parameter> v1;
//        vector<Parameter> v2;
//        vector<Parameter*>::iterator it = this->values.begin();
////        while (it != this->values.end()) {
////
////            it++;
////        }
//        for (vector<Parameter*>::iterator it = this->values.begin(); it != this->values.end(); it++) {
//
//        }
//        for (vector<Parameter*>::iterator it = other.values->begin(); it != other.values->end(); it++) {
//
//        }
        return (values < other.values);
    }
    
    vector<Parameter*> values;
private:
    
//    string name;
};

#endif /* Tuple_h */
