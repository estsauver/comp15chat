//
//  productionRule.cpp
//  psychadelicTuringTest
//
//  Created by Earl St Sauver on 3/13/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//


#include "grammar.h"


using namespace std;

void grammar::readIn(string fileName){
    ifstream inFile;
    int successfulOpen = openFileForReading(fileName, inFile);
    if (successfulOpen) {
        
        while(!atEndOfFile(inFile))
        {
            
            //
            productionRule phrase = *new productionRule;
            phrase.leftSide = getToken(inFile);
            string nextRightSideItem = getToken(inFile);
            while(nextRightSideItem != "."){
                phrase.rightSide.push_back(nextRightSideItem);
                nextRightSideItem =getToken(inFile);
            }
            grammarRules.push_back(phrase);
            
        }
        cout<<"File read Successfully!" << endl;
    }
    else{
        cout<<"Failure to Read File";
    }
    
}

void grammar::derive(


void grammar::printGrammar()
{
    cout<<endl<<"Printing Grammar"<< endl;
    for(int i= 0; i<grammarRules.size(); i++){
        grammarRules[i].printProductionRule();
    }
}

void productionRule::printProductionRule(){
    cout << leftSide;
    cout << " ";
    for (int i = 0; i<rightSide.size(); i++){
        cout << rightSide[i]<< " ";
    }
    cout<< endl;
}