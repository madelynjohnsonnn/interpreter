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
    bool isConstant(TokenType type);
private:
    
};

#endif /* Parameter_h */
