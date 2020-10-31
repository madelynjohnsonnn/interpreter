//
//  Header.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Header.h"

void Header::toString() {
    vector<Parameter*>::iterator it;
    for (it = attributes.begin(); it != attributes.end(); it++) {
        cout << *it;
    }
}

void Header::AddAttribute(Parameter* a) {
    attributes.push_back(a);
}
