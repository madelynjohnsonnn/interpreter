//
//  Relation.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Relation.h"

Relation::Relation(string name, Header* header) {
    this->name = name;
    this->header = header;
    //always start with empty set of tuples
}

void Relation::AddTuple(Tuple* t) {
    tuples.insert(t);
}

void Relation::toString() {
    cout << name << endl;
    header->toString();
    
    set <Tuple*>::iterator it;
    for (it = tuples.begin(); it != tuples.end(); it++) {
        (*it)->toString();
    }
    cout << endl;
}
