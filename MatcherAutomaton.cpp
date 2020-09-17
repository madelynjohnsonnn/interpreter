//
//  MatcherAutomaton.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/15/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "MatcherAutomaton.h"
#include <string>

//MatcherAutomaton::MatcherAutomaton(string toMatch, TokenType tokenType) {
//    this->toMatch = toMatch;
//}

int MatcherAutomaton::Read(const std::string& input) {
    bool isMatch = true;
    int inputRead = 0;
    
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    
    if (isMatch) {
        value = toMatch;
        inputRead = int(toMatch.size());
    }
    return inputRead;
}

int MatcherAutomaton::NewLinesRead() const {
    return 0;
}

Token* MatcherAutomaton::CreateToken(string input, int lineNumber) {
    return new Token(type, input, lineNumber);
}

string MatcherAutomaton::GetMatch() {
    return toMatch;
}
