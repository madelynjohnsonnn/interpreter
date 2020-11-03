//
//  Tuple.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Tuple.h"

//Tuple::Tuple(string n) {
//    name = n;
//}

Tuple::Tuple() {}

void Tuple::AddToTuple(Parameter* p) {
    values.push_back(p);
}

string Tuple::toString() {
    string returnVal;
    vector<Parameter*>::iterator it;
    for (it = values.begin(); it != values.end(); it++) {
        returnVal += (*it)->toString2() + " ";
    }
    return returnVal;
}
