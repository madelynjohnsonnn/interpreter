//
//  StringAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef StringAutomaton_h
#define StringAutomaton_h

#include <stdio.h>
#include <string>
#include "Token.h"
using namespace std;

class StringAutomaton {
public:
    StringAutomaton(string s);
    string Parse();
private:
    string input;
};

#endif /* StringAutomaton_h */
