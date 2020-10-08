//
//  PlainParameter.h
//  lab2
//
//  Created by Maddie Johnson on 10/7/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef PlainParameter_h
#define PlainParameter_h

#include <stdio.h>
#include <iostream>
#include "Parameter.h"
using namespace std;

class PlainParameter : public Parameter {
public:
    PlainParameter(string s) : Parameter() {
        value = s;
    }
    virtual void toString() {
        cout << value;
    }
    virtual void SetLeft(string l) {}
    virtual void SetRight(string r) {}
    virtual void SetOp(string o) {}
private:
    string value;
};

#endif /* PlainParameter_h */
