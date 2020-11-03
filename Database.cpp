//
//  Database.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Database.h"

void Database::toString() {
    map<string, Relation*>::iterator it;
    for (it = relations.begin(); it!= relations.end(); it++) {
        //cout << (*it).second->toString();
    }
}
