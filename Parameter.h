//
//  Parameter.h
//  lab2
//
//  Created by Maddie Johnson on 9/27/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Parameter_h
#define Parameter_h

#include <stdio.h>
#include "Token.h"
//#include "PlainParameter.h"
//#include "Expression.h"

class Parameter {
public:
    virtual void toString() {}
//    virtual void SetLeft(string l) = 0;
//    virtual void SetRight(string r) = 0;
//    virtual void SetOp(string o) = 0;
    virtual bool isConstant() = 0;
    virtual string GetName() = 0;
    virtual void SetNameAndType(string s, TokenType t) = 0; //TODO is this used anywhere??
    virtual string toString2() = 0;
private:
    
};

#endif /* Parameter_h */
