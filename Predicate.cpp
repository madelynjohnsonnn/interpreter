//
//  Predicate.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Predicate.h"
#include <iostream>
using namespace std;
//something with a name and a list of parameters

Predicate::Predicate() {
    name = "";
}

void Predicate::toString() {
    cout << "  " << name << "(";
    
    vector <Parameter*>::iterator it;
    unsigned int i = 0;
    for (it = parameters.begin(); it != parameters.end(); it++) {
        (*it)->toString();
        i++;
        if (i < parameters.size()) {
            cout << ",";
        }
    }
    cout << ")";
}

string Predicate::toString2() {
    string returnVal;
    returnVal += name + "(";
    
    vector <Parameter*>::iterator it;
    unsigned int i = 0;
    for (it = parameters.begin(); it != parameters.end(); it++) {
        (*it)->toString();
        i++;
        if (i < parameters.size()) {
            returnVal += ",";
        }
    }
    returnVal += ")";
    return returnVal;
}
