//
//  Parameter.cpp
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Parameter.h"
#include <iostream>
using namespace std;


bool Parameter::isConstant(TokenType type) { //STRING token, not ID
    if (type == STRING) {
        return true;
    }
    else if (type == ID) {
        return false;
    }
    else {
        cout << "not a string or id" << endl;
        return true;
    }
}
