//
//  Rule.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Rule.h"

string Rule::toString() {
    string out;
    out = headPredicate->GetName() + "(";
    vector <Parameter*>::iterator it;
    unsigned int i = 0;
    for (it = headPredicate->parameters.begin(); it != headPredicate->parameters.end(); it++) {
        out += (*it)->toString();
        i++;
        if (i < headPredicate->parameters.size()) {
            out += ",";
        }
    }
    
    out += ") :- ";
    
    vector <Predicate*>::iterator it2;
    unsigned int j = 0;
    for (it2 = bodyPredicates.begin(); it2 != bodyPredicates.end(); it2++) {
        if (j > 0) {
            out += ",";
        }
        j++;
        out += (*it2)->GetName() + "(";
        
        vector <Parameter*>::iterator it3;
        unsigned int k = 0;
        for (it3 = (*it2)->parameters.begin(); it3 != (*it2)->parameters.end(); it3++) {
            out += (*it3)->toString();
            k++;
            if (k < (*it2)->parameters.size()) {
                out += ",";
            }
            else {
                out += ")";
            }
        }
    }
    out += ".\n";
    return out;
}






/*
 
 vector <Parameter*>::iterator it;
 int i = 0;
 for (it = parameters.begin(); it != parameters.end(); it++) {
     (*it)->toString();
     i++;
     if (i < parameters.size()) {
         cout << ",";
     }
 }
 
 */
