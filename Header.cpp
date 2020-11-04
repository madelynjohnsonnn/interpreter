//
//  Header.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Header.h"

string Header::toString() {
    string returnVal;
    unsigned int i = 0;
    for (vector<Parameter*>::iterator it = attributes.begin(); it != attributes.end(); it++) {
        string str = (*it)->toString2();
        returnVal += str;
        i++;
        if (i < attributes.size()) {
            returnVal += ",";
        }
    }
    return returnVal;
}

void Header::AddAttribute(Parameter* a) {
    attributes.push_back(a);
}
