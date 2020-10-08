//
//  Rule.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Rule.h"

void Rule::toString() {
    cout << "  " << headPredicate->GetName() << "(";
    vector <Parameter*>::iterator it;
    int i = 0;
    for (it = headPredicate->parameters.begin(); it != headPredicate->parameters.end(); it++) {
        (*it)->toString();
        i++;
        if (i < headPredicate->parameters.size()) {
            cout << ",";
        }
    }
    
    cout << ") :- ";
    
    vector <Predicate*>::iterator it2;
    int j = 0;
    for (it2 = bodyPredicates.begin(); it2 != bodyPredicates.end(); it2++) {
        if (j > 0) {
            cout << ",";
        }
        j++;
        cout << (*it2)->GetName() << "(";
        
        vector <Parameter*>::iterator it3;
        int k = 0;
        for (it3 = (*it2)->parameters.begin(); it3 != (*it2)->parameters.end(); it3++) {
            (*it3)->toString();
            k++;
            if (k < (*it2)->parameters.size()) {
                cout << ",";
            }
            else {
                cout << ")";
            }
        }
    }
    cout << "." << endl;
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
