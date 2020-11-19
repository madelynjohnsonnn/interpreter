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

void Relation::AddTuple(Tuple t) {
    tuples.insert(t);
}

string Relation::toString() {
    string returnVal;
    
    vector<Tuple> v1;
    copy(tuples.begin(), tuples.end(), back_inserter(v1));
    
    for (vector<Tuple>::iterator it = v1.begin(); it != v1.end(); it++) {
        returnVal += "  ";
        returnVal += (it)->toString(header.attributes);
    }
    
//        for (set<Tuple>::iterator it = tuples.begin(); it != tuples.end(); it++) {
//            returnVal += "  ";
//            returnVal += (it)->toString(header.attributes);
//        }
    
    return returnVal;
}

Relation* Relation::select1(Relation* rel, int index, string value) {
    set<Tuple> newTuples;
    for (set<Tuple>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it).values.at(index)->GetName() == value) {
            newTuples.insert((*it));
        }
    }
    
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::select2(Relation* rel, int index1, int index2) {
    //returns a relation comprised of all tuples in the relation whose values at index1 and index2 are the same
    set<Tuple> newTuples;
    for (set<Tuple>::iterator it = rel->tuples.begin(); it != rel->tuples.end(); it++) {
        if ((*it).values.at(index1)->GetName() == (*it).values.at(index2)->GetName()) {
            newTuples.insert((*it));
        }
    }
    
    rel->tuples = newTuples;
    return rel;
}

Relation* Relation::project(Relation* rel, vector<int> pos) {
    set<Tuple> newTuples;
    vector <Parameter*> newAttributes;
    
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
        newAttributes.push_back(rel->header.attributes.at((*it)));
    }
    
    for (set<Tuple>::iterator it2 = rel->tuples.begin(); it2 != rel->tuples.end(); it2++) {
        Tuple tuple = Tuple();
        for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            Parameter* p = (*it2).values.at(*it);
            tuple.AddToTuple(p);
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
        Parameter* p = new Parameter((*it2),ID);
        newAttributes.push_back(p);
    }
    
    rel->header.attributes = newAttributes;
    return rel;
}

void Relation::Unionize(Tuple t) {
    //insert new tuples into relation
    tuples.insert(t);
    
    //TODO
    //if(mySet.insert(myTuple).second)
    //set.insert returns a pair: the second part is a bool saying if the inserted element was new to the set
    //If it already existed, do nothing more
    //If it is a new tuple, print it out

}

Relation* Relation::NaturalJoin(Relation* r) {
    Relation* joinedRelation = new Relation("result", CombineHeaders(this, r));
    
//    vector<Tuple> matches;
//    vector<Parameter*> commonHeaderNames;
//    for (vector<Parameter*>::iterator it = this->header.attributes.begin(); it != this->header.attributes.end(); it++) {
//        if (find(r->header.attributes.begin(), r->header.attributes.end(), (*it)) != r->header.attributes.end()) { //DOES CONTAIN
//            commonHeaderNames.push_back((*it));
//            break;
//        }
//    }
    
    int i = 0;
    vector<int> pos1;
    bool addVal = false;
    for (vector<Parameter*>::iterator it = this->header.attributes.begin(); it != this->header.attributes.end(); it++) {
//        if (find(r->header.attributes.begin(), r->header.attributes.end(), (*it)) != r->header.attributes.end()) { //DOES CONTAIN
        addVal = false;
        for (vector<Parameter*>::iterator it2 = r->header.attributes.begin(); it2 != r->header.attributes.end(); it2++) {
            if ((*it)->GetName() == (*it2)->GetName()) {
                addVal = true;
                break;
            }
        }
        if (addVal) {
            pos1.push_back(i);
        }
        i++;
    }
    
    i = 0;
    vector<int> pos2;
    addVal = false;
    for (vector<Parameter*>::iterator it = r->header.attributes.begin(); it != r->header.attributes.end(); it++) {
//        if (find(this->header.attributes.begin(), this->header.attributes.end(), (*it)) != this->header.attributes.end()) { //DOES CONTAIN
        addVal = false;
        for (vector<Parameter*>::iterator it2 = this->header.attributes.begin(); it2 != this->header.attributes.end(); it2++) {
            if ((*it)->GetName() == (*it2)->GetName()) {
                addVal = true;
                break;
            }
        }
        if (addVal) {
            pos2.push_back(i);
        }
        i++;
    }
    
//    Relation* r1 = project(this->Copy(), pos1);
//    Relation* r2 = project(r->Copy(), pos2);
    
    vector<Tuple> v1 = this->projectTuples(pos1);
    vector<Tuple> v2 = r->projectTuples(pos2);
    
    i = 0;
    int j = 0;
    int k = 0;
    
    
    for (vector<Tuple>::iterator it = v1.begin(); it != v1.end(); it++) {
        j = 0;
        for (vector<Tuple>::iterator it2 = v2.begin(); it2 != v2.end(); it2++) {
            
            if ((*it).equals((*it2))) {
                Tuple t1 = this->GetTupleAtIndex(i);
                Tuple t2 = r->GetTupleAtIndex(j);
                
                k = 0;
                for (vector<Parameter*>::iterator it3 = t2.values.begin(); it3 != t2.values.end(); it3++) {
                    //for (vector<int>::iterator it4 = pos2.begin(); it4 != pos2.end(); it4++) {
                    if (find(pos2.begin(), pos2.end(), k) == pos2.end()) { //DOES NOT CONTAIN
                        t1.AddToTuple((*it3));
                    }
                    k++;
                }
                
                joinedRelation->AddTuple(t1);
            }
            j++;
        }
        i++;
    }
    
    
    return joinedRelation;
}

Header Relation::CombineHeaders(Relation* r1, Relation* r2) {
    //adding in r1 attributes
    vector<Parameter*> combined = r1->header.attributes;
    
    //r2 attributes
    bool addVal = true;
    for (vector<Parameter*>::iterator it = r2->header.attributes.begin(); it != r2->header.attributes.end(); it++) {
//        if (std::find(combined.begin(), combined.end(), (*it)) == combined.end()) { //DOES NOT CONTAIN
        addVal = true;
        for (vector<Parameter*>::iterator it2 = combined.begin(); it2 != combined.end(); it2++) {
            if ((*it)->GetName() == (*it2)->GetName()) {
                addVal = false;
                break;
            }
        }
        if (addVal) {
            combined.push_back((*it));
        }
    }
    
    Header header;
    header.attributes = combined;
    
    return header;
}

Tuple Relation::GetTupleAtIndex(int index) {
    int i = 0;
    for (set<Tuple>::iterator it = this->tuples.begin(); it != this->tuples.end(); it++) {
        if (i == index) {
            return (*it);
        }
        i++;
    }
    Tuple* nullTuple = new Tuple();
    return *(nullTuple);
}


Relation* Relation::Copy() {
    Relation* returnVal = new Relation(this->name, this->header);
    for (set<Tuple>::iterator it = this->tuples.begin(); it != this->tuples.end(); it++) {
        returnVal->AddTuple((*it));
    }
    return returnVal;
}


vector<Tuple> Relation::projectTuples(vector<int> pos) {
    vector<Tuple> newTuples;
    
    for (set<Tuple>::iterator it2 = this->tuples.begin(); it2 != this->tuples.end(); it2++) {
        Tuple tuple = Tuple();
        for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            Parameter* p = (*it2).values.at(*it);
            tuple.AddToTuple(p);
        }
        newTuples.push_back(tuple);
    }
    
    return newTuples;
}


//bool Relation::IsJoinable(Tuple t1, Tuple t2) {
//
//    return true;
//}
