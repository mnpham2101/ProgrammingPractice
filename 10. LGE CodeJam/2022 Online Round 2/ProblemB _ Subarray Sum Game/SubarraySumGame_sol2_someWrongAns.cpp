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
int numberOfPositionInSubarray = 0;

void input() {
    cin >> n >> m;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    x.resize(m, 0);
    y.resize(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        // updata total number of positions in subarray
        // numberOfPositionInSubarray += y[i] - x[i] + 1;
    }

    // pre-process A
    sort(A.begin(), A.end(), greater<int>());
}

long long factorial(long long x) {
    long long fact = 1;
    for (long long i = 1; i <= x; i++) {
        fact = fact * i;
        fact = fact % 1000000007;
    }
    return fact;
}

void runLogic() {
    long long int sum = 0;
    long long int numberOfArrangement = 1;
    // mark boundary of subarray
    /*
    * position   |--1--|--2--|--3--|--4--|--5--|
    * index:     |--0--|--1--|--2--|--3--|
    * subarray1: |--1--|--2--|--3--|                     subarray position boundary {leftBoundary,rightBoundary} = {posistion1,position4}   => add {1,1} , {4,-1} to mp
    * subarray2:       |--2--|--3--|--4--|               subarray position boundary {leftBoundary,rightBoundary} = {posistion2,position5}   => add {2,1}, {5,-1} to mp
    */
    map<int, int> mp;                                                               // first: position, second: counting
    for (int i = 0; i < x.size(); i++) {
        mp[x[i]]++;
        mp[y[i] + 1]--;
    }
    // number of same occurance, f(0) = number of positions not in any subarray, f(2): number of position in 2 subarrays
    vector<int> freq(200001, 0);                                                    // m = 200000, có thể có đến 20000 subarray và 1 position có mặt trong tất cả subarray

    int maxfreq = 0;                                                                // maximum occurances in subarray
    int currentOccurance = 0;
    int previousBoundary = 1;                                                       // starting position as pos1
    int previousOccurance = 0;                                                      // first frequency to consider is 0 => calculate freq[0] = leftBoundaryOf1stSubarray - position1
    int currentBoundary = 0;

    for (auto it : mp)
    {
        currentOccurance += it.second;                                              // current occurance.
                                                                                    // current occurance +1 when it.first = leftBoundary => enter subarray
                                                                                    // current occurance -1 when it.first = rightBoundary => goes out of subarray

        /*  Update number of repetition of same occurance of positions in subarrays
        * position   |--1--|--2--|--3--|--4--|--5--|
        * index:     |--0--|--1--|--2--|--3--|
        * subarray1: |--1--|--2--|--3--|                     subarray position boundary {leftBoundary,rightBoundary} = {posistion1,position4}   => add {1,1} , {4,-1} to mp
        * subarray2:       |--2--|--3--|--4--|               subarray position boundary {leftBoundary,rightBoundary} = {posistion2,position5}   => add {2,1}, {5,-1} to mp
        * freq[2]  = 2 = LeftboundaryOfSubarray1 - RightboundaryOfSubarray2 = 4 - 2 =  (  it.first - prev  ) in 2nd iteration
        * freq[1]  = 2 = (LeftboundaryOfSubarray2 - LeftBoundaryOfSubarray1) + (RightboundaryOfSubarray2 - RightboundaryOfSubarray1)
        *              = (  it.first - prev  ) in 1st iteration              + (  it.first - prev  ) in 3rd iteration
        *              =      2 - 1                                          +      5 -4
        * freq[0]
        */
        int currentBoundary = it.first;
        freq[previousOccurance] += currentBoundary - previousBoundary;

        previousBoundary = currentBoundary;                                         // update previous position as current position
        previousOccurance = currentOccurance;                                       // update previous occurance as current occurance
        maxfreq = max(maxfreq, currentOccurance);                                   // update max occurance
    }

    // calculate number of positions not in any subarray, from the previousBoundary to the last position
    if (previousBoundary <= n) {
        freq[0] += n - previousBoundary + 1;
    }


    // calculate Sum
     int indexOfA = 0;
    for (int i = maxfreq; i >= 0; i--)
    {
        for (int j = 0; j < freq[i]; j++)
        {
            if (indexOfA < A.size()) {
                sum += A[indexOfA++] * i;                            // use higher values of items in A for locations that have higher frequency
            }
            else break;
        }
    }

    // calculate number of arrangement
    for (long long j = 0; j < freq.size(); j++)
    {
        numberOfArrangement *= (factorial(freq[j]) % (long long)1000000007);
        numberOfArrangement = numberOfArrangement % (long long)1000000007;
    }
    cout << sum << " " << numberOfArrangement << endl;
}



void runTestCase() {
    // set every global variables to 0;
    A.clear();
    x.clear();
    y.clear();
    numberOfPositionInSubarray = 0;
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