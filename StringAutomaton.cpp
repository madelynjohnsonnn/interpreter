//
//  StringAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "StringAutomaton.h"
#include <string>
using namespace std;

StringAutomaton::StringAutomaton(string s) {
    this->input = s;
}

string StringAutomaton::Parse() {
    if (input.substr(0) == "'") {
        //if (input.substr(1,1) == "'") { //empty string
        //    return input.substr(0,1);
        //}
        
        for (int i = 2; i < input.size(); i++) {
            if (input.substr(i,i) == "'") {
                return input.substr(0,i);
            }
        }
    }
    return NULL;
}
