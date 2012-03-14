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

void grammar::derive(string symbol){
    vector<productionRule> optionsHolder;
    
    //Reading in all options that match production rule
    for (int i = 0; i<grammarRules.size();i++){
        if (grammarRules[i].leftSide == symbol){
            optionsHolder.push_back(grammarRules[i]);
        }
    }
    //If the number of options is zero then we're at the end case and should print out
    
    if (optionsHolder.size()==0) {
        cout<< symbol<<" ";
    }else{
        //Now we need to pick a random option. Let's use random!
        int randomlySelectedIndex = random() % optionsHolder.size();
        
        for (int i = 0; i<optionsHolder[randomlySelectedIndex].rightSide.size() ; i++){
            derive(optionsHolder[randomlySelectedIndex].rightSide[i]);

        }
        
    }
}


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