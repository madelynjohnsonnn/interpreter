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
    vector<Parameter*>::iterator it;
    unsigned int i = 0;
    for (it = attributes.begin(); it != attributes.end(); it++) {
        cout << (*it)->toString2();
//        returnVal += (*it)->toString2();
        i++;
        if (i < attributes.size()) {
            returnVal += ",";
        }
    }
    return returnVal;
}

void Header::AddAttribute(Parameter* a) {
    attributes.push_back(a); //TODO ERROR BEING CAUSED HERE
}
