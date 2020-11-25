//
//  Parameter.h
//  lab2
//
//  Created by Maddie Johnson on 10/7/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Parameter_h
#define Parameter_h

#include <stdio.h>
#include <iostream>
#include "Token.h"
using namespace std;

class Parameter {
public:
    Parameter(string s, TokenType t) : Parameter() {
        value = s;
        type = t;
    }
    Parameter() {}
    void SetNameAndType(string s, TokenType t) {
        value = s;
        type = t;
    }
    string toString() {
        return value;
    }
    string toString2() {
        return value;
    }
    string GetName() {
        return value;
    }
//    TokenType GetType() {
//        return type;
//    }
    bool isConstant() { //STRING token, not ID
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
    bool operator< (const Parameter & other) const {
        return (this->value < other.value);
    }
//    virtual void SetLeft(string l) {}
//    virtual void SetRight(string r) {}
//    virtual void SetOp(string o) {}
private:
    string value;
    TokenType type;
};

#endif /* Parameter_h */
