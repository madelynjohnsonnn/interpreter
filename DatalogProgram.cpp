//
//  DatalogProgram.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "DatalogProgram.h"
#include <iostream>
#include <set>
using namespace std;

DatalogProgram::DatalogProgram(set <string> domains) {
    this->domains = domains;
}

void DatalogProgram::toString() {
    cout << "Success!" << endl;
    
    vector <Predicate*>::iterator it;
    for (it = schemes.begin(); it != schemes.end(); it++) {
        (*it)->toString(); //calling predicate tostring
    }
    
    for (it = facts.begin(); it != facts.end(); it++) {
        (*it)->toString();
    }
    
    vector <Rule*>::iterator it2;
    for (it2 = rules.begin(); it2 != rules.end(); it2++) {
        (*it)->toString();
    }
    
    for (it = queries.begin(); it != queries.end(); it++) {
        (*it)->toString();
    }
}
