//
//  Expression.h
//  lab2
//
//  Created by Maddie Johnson on 10/7/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include <iostream>
#include "Parameter.h"
using namespace std;

class Expression : public Parameter {
public:
    Expression(Parameter* l, Parameter* r, string o) : Parameter() {
        left = l;
        right = r;
        op = o;
    }
    Expression() : Parameter() {}
    void SetLeft(Parameter* l) {
        left = l;
    }
    void SetRight(Parameter* r) {
        right = r;
    }
    void SetOp(string o) {
        op = o;
    }
    void toString() {
        //todo
        cout << left << op << right;
    }
private:
    Parameter* left;
    Parameter* right;
    string op;
};

#endif /* Expression_h */
