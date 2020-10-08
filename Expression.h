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
    Expression();
    virtual void toString() {
        cout << left << op << right;
    }
private:
    string left;
    string right;
    string op;
};

#endif /* Expression_h */
