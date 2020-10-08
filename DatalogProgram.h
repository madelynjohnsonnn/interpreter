//
//  DatalogProgram.h
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef DatalogProgram_h
#define DatalogProgram_h

#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include "Predicate.h"
#include "Rule.h"
using namespace std;

class DatalogProgram {
public:
    DatalogProgram(set <string> domains);
    void toString();
    vector <Predicate*> schemes;
    vector <Predicate*> facts;
    vector <Predicate*> queries;
    vector <Rule*> rules;
private:
    set <string> domains; //only appears in the facts
};

#endif /* DatalogProgram_h */
