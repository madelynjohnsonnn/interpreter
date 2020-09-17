//
//  main.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Lexer.h"
using namespace std;

int main(int argc, const char * argv[]) {
    /*
    string nextLine;
    ifstream in(argv[1]);
    string fileContent = "";
    
    while (in.peek() != EOF) {
        fileContent += in.get();
    }
    cout << "filecontent" << fileContent << endl;
    
    Lexer * lexer = new Lexer();
    cout << "running lexer" << endl;
    
    lexer->run(fileContent);
    */
    
    Lexer * lexer = new Lexer();
    lexer->run("  :\n:(hello dad)");
    lexer->PrintTokens();
    
}
