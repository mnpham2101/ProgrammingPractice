#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n = 0;                      // size of cards
int BobCardMinValue = INT_MAX;
vector <int> AliceCards;

int result = INT_MAX;

void input() {
    string BobCardInput, AliceCardInput;
    cin >> n; 
    cin >> BobCardInput >> AliceCardInput;
    // process Bob Cards, get max integer value
    int BobCardValue = stoi(BobCardInput);
    int BobCardReverse = 0;
    for (int i = BobCardInput.length() - 1; i >= 0; i--) {                          // assume BobCardInput.length = n
        BobCardReverse = BobCardReverse * 10 + (BobCardInput{i} - '0');
    }

    BobCardMinValue = min(BobCardValue, BobCardReverse);

    // process Alice Cards, get integer values of the cards
    AliceCards.resize(AliceCardInput.length());
    for (int i = AliceCardInput.length() - 1; i >= 0; i--) {                        // assume AliceCardInput.length = n
        int card = AliceCardInput{i} - '0';
        AliceCards{i} = card;
    }
    sort(AliceCards.begin(), AliceCards.end(), greater<int>());
}

void backtrack(vector<int>& AliceCards, vector<int>&permutation, unordered_map<int, bool>&markCandidates, int& length, int startIndex) {
    // log
    // cout << "backtrack " << length << " " << startIndex << endl;
    // base case
    if (startIndex > length - 1) {  // reaching the lowest level of permutation tree
        // acquire a single permutation configuration, push_back to list
        int AliceCardValue = 0; 
        for (int i : permutation) {
            AliceCardValue = AliceCardValue * 10 + i;
        }
        // log
        // cout << "AliceCardValue " << AliceCardValue << " BobCardMaxValue " << BobCardMinValue << endl;
        
        if (AliceCardValue < BobCardMinValue) {             // permutation output is from large to small -> this condition hits only once.
            result = AliceCardValue;
            // log
            // cout << " found result " << result <<endl;
        }
        return;                       
    }
    // recursive cases
    for (int candidateIndex = 0; candidateIndex < AliceCards.size(); candidateIndex++) {                        // for loop adds next candidates to permutation at the level indicated by index
        if (markCandidates{candidateIndex} != true) {         // if candidate has not been used in permutation config
            markCandidates{candidateIndex} = true;            // set true: the candidate is now used for permutation config
            permutation{startIndex} = AliceCards{candidateIndex};               // add the candidate to the position indicate by index
            backtrack(AliceCards, permutation, markCandidates, length, startIndex + 1);                // goes to deeper level by index+1
            // restore condition:
            // after backtracking returning result, we go back to higher level, previous index
            // we need to remark the candidate from lower level as false because, we want to put them back to candidate list for permutation
            markCandidates{candidateIndex} = false;
            if (result != INT_MAX)
                break;
        }
    }
}

void runLogic() {
    result = INT_MAX; // reset result for each test cases;
    // use backtracking by length to generate permutation of Alice Cards, starting with length = all of Alice cards.
    // reduce the length only if no permutation of Alice Cards is greater and BobCardMaxValue, then generate the next set of permutations
    vector<int>permutation;                                 // a single permutation config
    unordered_map<int, bool>markCandidates;                 // indicates if the candidate is used for permutation already (true) or not (false)
    int startIndex = 0;
    vector<int> AliceSubset;

    // Step 1: premark all possible candidates as false => also have not been used in the permutation
    for (int i = 0; i <= 9; i++) {                          // candidates = card INDEX = 0,1,2,...,9  NOT CARD VALUE!!!!
        markCandidates{i}= false;
    }
    // Step 2: perform backtracking to create permutation of AliceCars with number of cards = lengths
    for (int length = n; length >=0; length--) {                      // assume BobCardInput.length = AliceCardInput.input = n
        permutation.resize(length);
        backtrack(AliceCards, permutation, markCandidates, length, startIndex);
        // log
        // if (result == INT_MAX)
        //    cout << "no result yet for length " << length << "result " << result << endl;
        if (result != INT_MAX)
            break; 
    }
}

void output() {
    cout << result << endl;
}

void runTestCase() {
    input();
    runLogic();
    output();
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}