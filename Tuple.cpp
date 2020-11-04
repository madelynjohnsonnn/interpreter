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

string Tuple::toString(vector<Parameter*> headAttributes) {
    string returnVal = "";
    int i = 0;
    for (vector<Parameter*>::iterator it = values.begin(); it != values.end(); it++) {
        returnVal += headAttributes.at(i)->toString2() + "=";
        
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
