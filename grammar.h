//
//  productionRule.h
//  psychadelicTuringTest
//
//  Created by Earl St Sauver on 3/13/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#ifndef psychadelicTuringTest_productionRule_h
#define psychadelicTuringTest_productionRule_h
#include "fstream"
#include "comp11io.h"
#include <iostream>
#include <vector>


class productionRule {
    public:
    string leftSide;
    vector<string> rightSide;
    void printProductionRule();
};


class grammar {
public:

    vector<productionRule> grammarRules;
    
    void readIn(string fileName);
    
    
    //Debugging Methods
    void printGrammar();
    
    
};

#endif
