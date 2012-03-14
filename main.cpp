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
    string filename;
    if (argc != 2) {
        cout << "usage: arv[0] filename.txt";
    } else {
        filename= argv[1];

    }
    
    srandom(time(NULL));
    //Testing File Input
    grammar testGrammer;
    testGrammer.readIn(filename);
    
//    testGrammer.readIn("/Users/estsauver/Documents/CurrentClasses/CS15/grammar.txt");
//    testGrammer.printGrammar();
    
    string userInput;
    do {
        cin >> userInput;
        testGrammer.derive("Sentence");
        cout<< endl;
    } while (userInput != "q");
    return 0;
}

