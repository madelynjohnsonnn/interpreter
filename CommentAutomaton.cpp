//
//  CommentAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "CommentAutomaton.h"
#include <string>
using namespace std;

CommentAutomaton::CommentAutomaton(string s) {
    this->input = s;
}

string CommentAutomaton::Parse() {
    //LINE COMMENT
    if (input.substr(0) == "#") {
        for (int i = 0; i < input.size(); i++) {
            while (input.substr(i,i) != "/n") {
                
            }
        }
    }
    
    //BLOCK COMMENT
    
    
    return NULL;
}
