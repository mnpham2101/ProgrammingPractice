#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int minDiff = 2147483647;

void input(string& card) {
    cin >> card;
}

bool compare(string& card, int position) {
    char tmp = card[position];

    if ((tmp == 'A')
        || (tmp == 'B')
        || (tmp == 'E')
        || (tmp == 'R')
        || (tmp == 'T')) {
        return true;
    }
    else return false;
}

bool compareAlice(string& card, int position) {
    char tmp = card[position];

    if ((tmp == 'A')
        || (tmp == 'L')
        || (tmp == 'I')
        || (tmp == 'C')
        || (tmp == 'E')) {
        return true;
    }
    else return false;
}

// brute force
void recursive_turnResult(string& card, int left, int right, int albertScore, int aliceScore, bool albertTurn, int& result) {
    // base case: end game.  
    if (left > right) {
        int scoreDifferent = albertScore - aliceScore;
        result = min(result, scoreDifferent);
        return;
    }

    else if (albertTurn) {
        albertTurn = !albertTurn;
        // if both leftmost card and rightmost card can give him points, Albert always takes the leftmost card
        if (compare(card, left)) {
            recursive_turnResult(card, left + 1, right, albertScore + 2, aliceScore, albertTurn, result);
        }
        // If only one of the two cards can give him points, Albert always takes the card that can give him points.
        else if (compare(card, right)) {
            recursive_turnResult(card, left, right - 1, albertScore + 2, aliceScore, albertTurn, result);
        }
        // If neither of the two cards can give him points, Albert always takes the rightmost card and gets no score
        else {
            recursive_turnResult(card, left, right - 1, albertScore, aliceScore, albertTurn, result);
        }
    }

    else if (!albertTurn) {
        // Alice can take any card of left or right to score
        // but Alice wants to make less score ...
        albertTurn = !albertTurn;
        if (compareAlice(card, right)) recursive_turnResult(card, left, right - 1, albertScore, aliceScore + 1, albertTurn, result);
        else recursive_turnResult(card, left, right - 1, albertScore, aliceScore, albertTurn, result);

        if (compareAlice(card, left)) recursive_turnResult(card, left + 1, right, albertScore, aliceScore + 1, albertTurn, result);
        else recursive_turnResult(card, left + 1, right, albertScore, aliceScore, albertTurn, result);
    }
}

int runLogic(string& card) {
    int albertScore = 0;
    int aliceScore = 0;
    int left = 0;
    int right = card.length() - 1;
    bool albertTurn = true;
    int result = minDiff;
    // results are from consecutive play turns where start, end, score are calculated by previous turn
    // therefore, use recursive call
    recursive_turnResult(card, left, right, albertScore, aliceScore, albertTurn, result);

    if (result < 0) return -1;
    else return result;
}

void output(int result) {
    cout << result << endl;
}

// void output(queue<int>&resultList){
//     while (resultList.size() !=0){
//         int testCaseResult = resultList.front();                    // first in first out
//         cout<<testCaseResult<<endl;
//         resultList.pop();
//     }
// }

void runTestCase() {
    string card;
    input(card);
    int result = runLogic(card);
    output(result);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}