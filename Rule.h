//
//  Rule.h
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Rule_h
#define Rule_h

#include <stdio.h>
#include <vector>
#include "Parameter.h"
#include "Predicate.h"
#include <iostream>
using namespace std;

class Rule{
public:
    Rule() {}
    
    void SetHeadPredicate(Predicate* n) {
        headPredicate = n;
    }
    
    void AddBodyPredicate(Predicate* bp) {
        bodyPredicates.push_back(bp);
    }
    
    string toString();
    
    Predicate* headPredicate;
    vector<Predicate*> bodyPredicates;
private:
    
};

#endif /* Rule_h */
