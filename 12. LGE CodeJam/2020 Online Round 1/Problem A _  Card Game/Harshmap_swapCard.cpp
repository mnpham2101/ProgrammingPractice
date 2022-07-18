#include<string>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;

queue<bool> resultList;

void input(vector<string> & cardAfter, vector<string> & cardBefore){
    int numberOfCard;
    cin>>numberOfCard;
    string card;

    for (int i = 1; i<=numberOfCard; i++){
        cin>>card;
        cardBefore.push_back(card);
    }

    for (int i = 1; i<=numberOfCard; i++){
        cin>>card;
        cardAfter.push_back(card);
    }
}

void runLogic(vector<string> cardBefore, vector<string> cardAfter, queue<bool>&resultList){
    map<string, int> countCardBefore;
    map<string, int> countCardAfter;
    for (auto card : cardBefore){
        countCardBefore[card]++;
    }

    for (auto card : cardAfter){
        countCardAfter[card]++;
    }
    bool testCaseResult = false;
    for (auto & card: countCardBefore){
        string cardName = card.first;
        int quantityBefore = card.second;
        auto cardAfter = countCardAfter.find(cardName);
        if (cardAfter == countCardAfter.end()) {
            testCaseResult = false;    //  can't find card => CHEATER
            break;                     // break if false
        }
        else {
            int count = cardAfter->second;
            if(quantityBefore == count) {
                testCaseResult = true;          // NOT A CHEATER
            }
            else{
                testCaseResult = false;         // not same quantity =>  CHEATER
                break;
            }

        }
    }

    resultList.push(testCaseResult);

}

void output(queue<bool>&resultList){
    while (!resultList.empty()){
        bool testCaseResult = resultList.front();                    // first in first out
        if (testCaseResult == true) cout <<"NOT CHEATER"<<endl;
        else cout <<"CHEATER"<<endl;
        resultList.pop();
    }
}

void runTestCase(){
    vector<string> cardBefore;
    vector<string> cardAfter;

    input(cardBefore, cardAfter);
    runLogic(cardBefore, cardAfter,resultList);

}

int main(){
    int T;
    cin>>T;
    for (int i=1; i<=T; i++){
        runTestCase();
    }
    output(resultList);
}