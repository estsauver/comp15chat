//
//  main.cpp
//  psychadelicTuringTest
//
//  Created by Earl St Sauver on 3/13/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//
#include "grammar.h"
#include <iostream>

int main (int argc, const char * argv[])
{
    srandom(time(NULL));
    //Testing File Input
    grammar testGrammer;
    testGrammer.readIn("/Users/estsauver/Documents/CurrentClasses/CS15/grammar.txt");
    testGrammer.printGrammar();
    testGrammer.derive("NP");
    return 0;
}

