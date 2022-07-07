#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int n = 0;                      // size of input array A
int m = 0;                      // number of pairs
vector <int> A;                 // input vector A
vector <int> x;                 // x, y for subarray range from x to y. size of x = m = number of subarrays
vector <int> y;
vector<int>check;
unordered_map<int, int> position_frequency;        // the position and their occurance in subarray
                                                   // first: position; second: its occurance
/*
int position_value_frequency[50000][200000];       // stores position_value_frequency for quick calculating sum
                                                   // row = position = limit of n
                                                   // col = frequency = limit of number of subarrays or number of pairs
*/
int result = INT_MAX;

void input() {
    cin >> n >> m;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    x.resize(m, 0);
    y.resize(m, 0);
    check.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        // Step 1: count position's frequency in subarray
        for (int j = x[i]; j <= y[i]; j++) {
            position_frequency[j]++;
            check[j] = true;
        }
    }

    // pre-process A

    sort(A.begin(), A.end(), greater<int>());
}

int factorial(int x) {
    int fact = 1;
    for (int i = 1; i <= x; i++) {
        fact = fact * i;
    }
    return fact;
}

void runLogic() {
    vector<pair<int, int>> sorted_position_freq;                      // this vector will sort auto in ascending order of frequency
                                                                      // first : position
                                                                      // second: frequency
    vector<int>countSameFreq(200000, 0);                                                 // this vector counts how many time a same frequency is repeatedv
                                                                      // count(0) counts remaining items not used in any subarray.
                                                                      // count(1) number of times a position is used 1 time in a subarray.
                                                                      // count(2) number of times a position is used 2 time in a subarray
                                                                      // size of count is number of subarrays or m+1
    // Step 2.1: put the pair(position_frequecy in the map to vector for sorting
    // Step 2.2: also count the number of same repetition
    for (auto i : position_frequency) {
        sorted_position_freq.emplace_back(i);
        int freq = i.second;
        countSameFreq[freq]++;
    }
    for (int i = 1; i < check.size(); i++) {                           // Notes: this is redundant - making algo too long
        if (check[i] == false) {
            countSameFreq[0]++;
        }
    }

    // Step 2.1: sort the positions based on decreasing occurance
    sort(sorted_position_freq.begin(), sorted_position_freq.end(),
        [](const auto& position1, const auto& position2) { return position1.second > position2.second; });

    // Step 3.1: re-arrange A, assign higher values of A to positions that have more occurance,
                                                                       // Notes: this is redundant - making algo too long - there is no need for this map
    unordered_map<int, int> position_value(m);                         // map keeps track of value of rearranged A at a position
                                                                       // first: position
                                                                       // second: higher value of A to be placed at the position
    int index = 0;
    long long int sum = 0;
    // Step 3.1: calculate sum                                          // Notes: this is redundant, could combine 3.1 and 3.2
    for (auto i : sorted_position_freq) {
        position_value.emplace(i.first, A[index]);
        index++;
        int position = i.first;
        int valueOfA_atPosition = position_value[position];
        int freqOfthePosition = i.second;
        sum += valueOfA_atPosition * freqOfthePosition;
    }
    // Step 3.2: calculate arrangement
    long long int numberOfArrangement = 1;
    for (int i = 0; i < countSameFreq.size(); i++) {
        if (i == 0 && countSameFreq[i] == 0)              // conner case: there is no item in A that is not in subarray
            continue;
        else if (countSameFreq[i] == 0) {       // for other cases
            break;
        }
        numberOfArrangement *= factorial(countSameFreq[i]);
        numberOfArrangement = numberOfArrangement % 100000007;
    }

    cout << sum << " " << numberOfArrangement << endl;
}

void runTestCase() {
    A.clear();
    x.clear();
    y.clear();
    check.clear();
    position_frequency.clear();
    input();
    runLogic();
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}