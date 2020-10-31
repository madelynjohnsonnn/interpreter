//
//  Tuple.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Tuple.h"

Tuple::Tuple(string n) {
    name = n;
}

void Tuple::AddToTuple(string s) {
    values.push_back(s);
}

void Tuple::toString() {
    vector<string>::iterator it;
    for (it = values.begin(); it != values.end(); it++) {
        cout << (*it) << " ";
    }
}
