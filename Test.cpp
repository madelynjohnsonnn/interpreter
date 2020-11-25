//
//  TestParser.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/6/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Test.h"
#include "Relation.h"
#include <vector>
using namespace std;
#include <iostream>

void Test::TestJoin() {
    Parameter* one = new Parameter("cat", STRING);
    Parameter* two = new Parameter("dog", STRING);
    Parameter* three = new Parameter("fish", STRING);
    
    Header* firstH = new Header();
    firstH->AddAttribute(one);
    firstH->AddAttribute(two);
    firstH->AddAttribute(three);
    
    Relation* first = new Relation("first", *(firstH));
    
    Tuple* tone = new Tuple();
    Parameter* pone = new Parameter("1", STRING);
    Parameter* ptwo = new Parameter("2", STRING);
    Parameter* pthree = new Parameter("5", STRING);
    tone->AddToTuple(pone);
    tone->AddToTuple(ptwo);
    tone->AddToTuple(pthree);
    
    first->AddTuple((*tone));
    
    Tuple* t2 = new Tuple();
    Parameter* p4 = new Parameter("1", STRING);
    Parameter* p5 = new Parameter("4", STRING);
    Parameter* p6 = new Parameter("1", STRING);
    t2->AddToTuple(p4);
    t2->AddToTuple(p5);
    t2->AddToTuple(p6);
    
    first->AddTuple((*t2));
    
    Tuple* t3 = new Tuple();
    Parameter* p7 = new Parameter("2", STRING);
    Parameter* p8 = new Parameter("3", STRING);
    Parameter* p9 = new Parameter("2", STRING);
    t3->AddToTuple(p7);
    t3->AddToTuple(p8);
    t3->AddToTuple(p9);
    
    first->AddTuple((*t3));
    
    Tuple* t4 = new Tuple();
    Parameter* p10 = new Parameter("3", STRING);
    Parameter* p11 = new Parameter("3", STRING);
    Parameter* p12 = new Parameter("2", STRING);
    t4->AddToTuple(p10);
    t4->AddToTuple(p11);
    t4->AddToTuple(p12);
    
    first->AddTuple((*t4));
    
    Tuple* t5 = new Tuple();
    Parameter* p13 = new Parameter("6", STRING);
    Parameter* p14 = new Parameter("7", STRING);
    Parameter* p15 = new Parameter("4", STRING);
    t5->AddToTuple(p13);
    t5->AddToTuple(p14);
    t5->AddToTuple(p15);
    
    first->AddTuple((*t5));
    
    
    
    //RELATION 2
    
    Parameter* four = new Parameter("cat", STRING);
    Parameter* five = new Parameter("fish", STRING);
    Parameter* six = new Parameter("bird", STRING);
    Parameter* seven = new Parameter("bunny", STRING);
    
    Header* secondH = new Header();
    secondH->AddAttribute(four);
    secondH->AddAttribute(five);
    secondH->AddAttribute(six);
    secondH->AddAttribute(seven);
    
    Relation* second = new Relation("second", *(secondH));
    
    Tuple* t6 = new Tuple();
    Parameter* p16 = new Parameter("3", STRING);
    Parameter* p17 = new Parameter("4", STRING);
    Parameter* p18 = new Parameter("2", STRING);
    Parameter* p19 = new Parameter("4", STRING);
    t6->AddToTuple(p16);
    t6->AddToTuple(p17);
    t6->AddToTuple(p18);
    t6->AddToTuple(p19);
    
    second->AddTuple((*t6));
    
    Tuple* t7 = new Tuple();
    Parameter* p20 = new Parameter("6", STRING);
    Parameter* p21 = new Parameter("4", STRING);
    Parameter* p22 = new Parameter("9", STRING);
    Parameter* p23 = new Parameter("2", STRING);
    t7->AddToTuple(p20);
    t7->AddToTuple(p21);
    t7->AddToTuple(p22);
    t7->AddToTuple(p23);
    
    second->AddTuple((*t7));
    
    Tuple* t8 = new Tuple();
    Parameter* p24 = new Parameter("4", STRING);
    Parameter* p25 = new Parameter("3", STRING);
    Parameter* p26 = new Parameter("2", STRING);
    Parameter* p27 = new Parameter("7", STRING);
    t8->AddToTuple(p24);
    t8->AddToTuple(p25);
    t8->AddToTuple(p26);
    t8->AddToTuple(p27);
    
    second->AddTuple((*t8));
    
    Tuple* t9 = new Tuple();
    Parameter* p28 = new Parameter("1", STRING);
    Parameter* p29 = new Parameter("5", STRING);
    Parameter* p30 = new Parameter("2", STRING);
    Parameter* p31 = new Parameter("4", STRING);
    t9->AddToTuple(p28);
    t9->AddToTuple(p29);
    t9->AddToTuple(p30);
    t9->AddToTuple(p31);
    
    second->AddTuple((*t9));
    
    Tuple* t10 = new Tuple();
    Parameter* p32 = new Parameter("1", STRING);
    Parameter* p33 = new Parameter("5", STRING);
    Parameter* p34 = new Parameter("8", STRING);
    Parameter* p35 = new Parameter("3", STRING);
    t10->AddToTuple(p32);
    t10->AddToTuple(p33);
    t10->AddToTuple(p34);
    t10->AddToTuple(p35);
    
    second->AddTuple((*t10));
    
    Tuple* t11 = new Tuple();
    Parameter* p36 = new Parameter("3", STRING);
    Parameter* p37 = new Parameter("2", STRING);
    Parameter* p38 = new Parameter("1", STRING);
    Parameter* p39 = new Parameter("2", STRING);
    t11->AddToTuple(p36);
    t11->AddToTuple(p37);
    t11->AddToTuple(p38);
    t11->AddToTuple(p39);
    
    second->AddTuple((*t11));
    
    first->NaturalJoin(second);
}
