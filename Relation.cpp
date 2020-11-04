//
//  Relation.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Relation.h"

Relation::Relation(string name, Header header) {
    this->name = name;
    this->header = header;
    //always start with empty set of tuples
}

void Relation::AddTuple(Tuple* t) {
    tuples.insert(t);
}

string Relation::toString() {
    string returnVal;
//    returnVal += name + "(";
//    returnVal += header.toString();
//    returnVal += ")";
    
    for (set <Tuple*>::iterator it = tuples.begin(); it != tuples.end(); it++) {
        returnVal += "  ";
        returnVal += (*it)->toString(header.attributes);
    }
    return returnVal;
}

Relation* Relation::select1(Relation* rel, int index, string value) {
    set<Tuple*> newTuples;
    for (set<Tuple*>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it)->values.at(index)->GetName() == value) {
            newTuples.insert((*it));
        }
    }
    
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::select2(Relation* rel, int index1, int index2) {
    //returns a relation comprised of all tuples in the relation whose values at index1 and index2 are the same
    set<Tuple*> newTuples;
    for (set<Tuple*>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it)->values.at(index1)->GetName() == (*it)->values.at(index2)->GetName()) {
            newTuples.insert((*it));
        }
    }
    
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::project(Relation* rel, vector<int> pos) {
    set<Tuple*> newTuples;
    vector <Parameter*> newAttributes;
    
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
        newAttributes.push_back(rel->header.attributes.at((*it)));
    }
    
    for (set<Tuple*>::iterator it2 = rel->tuples.begin(); it2 != rel->tuples.end(); it2++) {
        Tuple* tuple = new Tuple();
        for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            Parameter* p = (*it2)->values.at(*it);
            tuple->AddToTuple(p);
        }
        newTuples.insert(tuple);
    }
    
    rel->header.attributes = newAttributes;
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::rename(Relation* rel, vector<string> newHeader) {
    //just change header
    vector <Parameter*> newAttributes;
    
    for (vector<string>::iterator it2 = newHeader.begin(); it2 != newHeader.end(); it2++) {
        Parameter* p = new PlainParameter((*it2),ID);
        newAttributes.push_back(p);
    }
    
    rel->header.attributes = newAttributes;
    return rel;
}
