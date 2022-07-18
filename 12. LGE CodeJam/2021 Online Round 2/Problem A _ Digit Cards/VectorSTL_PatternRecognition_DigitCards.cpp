#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void input(vector<int>& cardList) {
    int card;
    for (int i = 1; i <= 9; i++) {
        cin >> card;                               //input indicate the number of cards whose value = i.
        if (i == 6) {
            for (int j = 1; j <= card; j++) {
                cardList.push_back(9);
            }
        }
        else if (i != 6) {
            for (int j = 1; j <= card; j++) {
                cardList.push_back(i);              //push back card = i the number of times = card
            }
        }
    }
}

vector<int> runLogic(vector<int>& cardList) {
    // Step 1: sort the cards
    sort(cardList.begin(), cardList.end(), greater<int>());         // sort in descending order, back = [i=0] = higher value
    int n = cardList.size();
    vector <int> result(n);
    int left = 0;
    int right = n - 1;
    // while (left < right) {
    // Step 2: arrange the cards according to order to make the highest value cards. 
    // use left and right to keep track of the positions to place the card in each turn                                              
        for (int i = 0; i < n; i++) {                   // increment the turns
            if (i % 2 == 0) {                           // if the turn is even => put the card on the left
                result[left] = cardList[i];
                left++;
            }
            if (i % 2 != 0) {                           // if the turn is odd => put the card on the right
                result[right] = cardList[i];
                right--;
            }
        }
    // }
    return result;
}

void output(vector<int>& resultCard) {
    for (int i = 0; i < resultCard.size(); i++) {
        cout << resultCard[i] << " ";
    }
    cout << endl;
}

// void output(queue<int>&resultList){
//     while (resultList.size() !=0){
//         int testCaseResult = resultList.front();                    // first in first out
//         cout<<testCaseResult<<endl;
//         resultList.pop();
//     }
// }

void runTestCase() {
    vector<int> cardList;
    input(cardList);
    runLogic(cardList);
    vector<int> result = runLogic(cardList);
    output(result);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}