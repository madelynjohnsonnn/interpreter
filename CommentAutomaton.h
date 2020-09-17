//
//  CommentAutomaton.h
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef CommentAutomaton_h
#define CommentAutomaton_h

#include <stdio.h>
#include <string>
using namespace std;

class CommentAutomaton {
public:
    CommentAutomaton(string s);
    string Parse();
private:
    string input;
};

#endif /* CommentAutomaton_h */
