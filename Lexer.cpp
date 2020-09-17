//
//  Lexer.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Lexer.h"
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

Lexer::Lexer() {
    machines.push_back(new MatcherAutomaton(",", COMMA));
    machines.push_back(new MatcherAutomaton(".", PERIOD));
    machines.push_back(new MatcherAutomaton("?", Q_MARK));
    machines.push_back(new MatcherAutomaton("(", LEFT_PAREN));
    machines.push_back(new MatcherAutomaton(")", RIGHT_PAREN));
    machines.push_back(new MatcherAutomaton(":", COLON));
    machines.push_back(new MatcherAutomaton(":-", COLON_DASH));
    machines.push_back(new MatcherAutomaton("*", MULTIPLY));
    machines.push_back(new MatcherAutomaton("+", ADD));
    machines.push_back(new MatcherAutomaton("Schemes", SCHEMES));
    machines.push_back(new MatcherAutomaton("Facts", FACTS));
    machines.push_back(new MatcherAutomaton("Queries", QUERIES));
    machines.push_back(new IdAutomaton(ID));
    //string
    //comment
    //undefined
    machines.push_back(new MatcherAutomaton("\n", EOFILE));
}


void Lexer::run(string fileContents) {
    int curLineNum = 1;
    int maxRead = 0;
    int inputRead = 0;
    int maxNewLines = 0;
    Automaton* maxMachine = NULL;
    
    while (fileContents.size() > 0) {
        cout << fileContents << endl;
        maxMachine = NULL;
        maxRead = 0;
        
        while (isspace(fileContents.at(0))) {
            if (fileContents.at(0) == '\n') {
                curLineNum++;
            }
            cout << "erasing " << fileContents.at(0) << endl;
            fileContents.erase(0,1);
        }
        
        
        vector <Automaton*>::iterator it;
        for (it = machines.begin(); it != machines.end(); it++) {
            inputRead = (*it)->Read(fileContents);
            
//            cout << "Machines: " << (*it)->GetType() << " Input read: " << inputRead << endl;
            
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxMachine = (*it);
                maxNewLines = (*it)->NewLinesRead();
                cout << "type: " << (*it)->GetType() << ", maxRead: " << maxRead << ", Max New lines: " << maxNewLines <<  endl;
            }
        }
        
        if (maxRead > 0) {
            cout << "Creating token for " << maxMachine->GetValue() << endl;
            
            Token* newToken = maxMachine->CreateToken(maxMachine->GetValue(), curLineNum);
            
            cout << "newToken: " << newToken->toString() << endl;
            
            curLineNum += maxNewLines;
            tokens.push_back(newToken);
        }
        else {
            maxRead = 1;
            Token* newToken = new Token(UNDEFINED, fileContents.substr(0), curLineNum);
            tokens.push_back(newToken);
        }
        fileContents.erase(0, maxRead);
    }
}

void Lexer::PrintTokens() {
    vector <Token*>::iterator it;
    for (it = tokens.begin(); it != tokens.end(); it++) {
        cout << (*it)->toString() << endl;
    }
}
