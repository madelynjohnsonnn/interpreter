//
//  Predicate.h
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Predicate_h
#define Predicate_h

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include "Parameter.h"
using namespace std;

class Predicate {
public:
    Predicate();
    void toString();
    void SetName(string n) {
        name = n;
    }
    vector <Parameter*> parameters;
private:
    string name;
    
};

#endif /* Predicate_h */
