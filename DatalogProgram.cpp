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

DatalogProgram::DatalogProgram(set <string> d) {
    domains = d;
}

void DatalogProgram::toString() {
    cout << "Success!" << endl;
    
    cout << "Schemes(" << schemes.size() << "):" << endl;
    vector <Predicate*>::iterator it;
    for (it = schemes.begin(); it != schemes.end(); it++) {
        (*it)->toString(); //calling predicate tostring
        cout << ")" << endl;
    }
    
    
    cout << "Facts(" << facts.size() << "):" << endl;
    for (it = facts.begin(); it != facts.end(); it++) {
        (*it)->toString();
        cout << ")." << endl;
    }
    
    
    cout << "Rules(" << rules.size() << "):" << endl;
    vector <Rule*>::iterator it2;
    for (it2 = rules.begin(); it2 != rules.end(); it2++) {
        (*it)->toString();
    }
    
    cout << "Queries(" << queries.size() << "):" << endl;
    for (it = queries.begin(); it != queries.end(); it++) {
        (*it)->toString();
    }
    
    cout << "Domains(" << domains.size() << "):" << endl;
    set <string>::iterator it3;
    for (it3 = domains.begin(); it3 != domains.end(); it3++) {
        cout << "  " << *it3 << endl;
    }
}

void DatalogProgram::SetDomain(set <string> d) {
    domains = d;
}
