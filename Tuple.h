//
//  Tuple.h
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Tuple_h
#define Tuple_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Tuple {
public:
    Tuple(string n);
    void AddToTuple(string s);
    void toString();
private:
    bool operator< (const Tuple & other) const {
        return (this->values < other.values);
    }
    vector <string> values;
    string name;
};

#endif /* Tuple_h */
