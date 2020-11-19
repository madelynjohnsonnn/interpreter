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
    
    string toString(const vector<Parameter*> header) {
        string returnVal = "";
        int i = 0;
        for (vector<Parameter*>::iterator it = values.begin(); it != values.end(); it++) {
            returnVal += header.at(i)->toString2() + "=";
            
            if (it == values.end() - 1) {
                returnVal += (*it)->toString2() + "\n";
            }
            else {
                returnVal += (*it)->toString2() + ", ";
            }
            i++;
        }
        return returnVal;
    }
    
    bool operator< (const Tuple & other) const {
        vector<Parameter> v1;
        vector<Parameter> v2;
        for (unsigned int i = 0; i < this->values.size(); i++) {
            Parameter* p = this->values.at(i);
            v1.push_back(*p);
        }
        for (unsigned int i = 0; i < other.values.size(); i++) {
            v2.push_back(*(other.values.at(i)));
        }
        bool returnVal = v1 < v2;
        return returnVal;
    }
    
    bool operator== (const Tuple & other) const {
        if (this->values.size() != other.values.size()) {
            return false;
        }
        for (unsigned int i = 0; i < this->values.size(); i++) {
            Parameter* p = this->values.at(i);
            if (p->GetName() != other.values.at(i)->GetName()) {
                return false;
            }
        }
        return true;
    }
    bool equals (const Tuple & other) const {
        if (this->values.size() != other.values.size()) {
            return false;
        }
        for (unsigned int i = 0; i < this->values.size(); i++) {
            Parameter* p = this->values.at(i);
            if (p->GetName() != other.values.at(i)->GetName()) {
                return false;
            }
        }
        return true;
    }
    vector<Parameter*> GetValues() {
        return values;
    }
    
    
    vector<Parameter*> values;
};

#endif /* Tuple_h */
