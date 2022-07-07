#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

queue<int>resultList;

void input() {
}

// count a number of digit from a value.
int countDigit(long long int Xn) {
    return floor(log10(Xn) + 1);
}

// find a number after a number of digit is cut off from the right
int cutOff(long long int Xn, int numberOfDigitTobeCutOff) {
    for (int count = 0; count < numberOfDigitTobeCutOff; count++) {
        Xn /= 10;
    }
    return Xn;
}

/*
* observe that the long number is : X1*10^(c-1) + X2*10^(c-2) + .... Xn*(10^0)   ==> to solve this problem, we need to find Xn. 
  For example: a=1,b=1,c=15
  The long number is 123456789101112 = 1*10^14 + 2*10^13 + 3*10^12 + ... + 9*10^6 + 10*10^4 + 11*10^2 + 12
  where X1=1, X2=2 .... Xn= 12
* the number of digit in X1, X2, Xn could be found by .... 
* Xn is calculated by for loop until the number of digit is greater than c. 
* For every X1, X2, .... Xn, the number of digit could be counted. 
*/

void runLogic(int a, int b, int c) {
    int i = 0;
    int Xn = 0;
    int result = 0;
    int numLength = 0;
    int totalNumLength = 0;
    // Step 1: generate the series the get Xn
    while (totalNumLength <= c) {                       // Time out due to complexity O(n)
        Xn = a + b * i;
        // Log
        // cout << Xn << " ";
        i++;                                            // since i++ is added after Xn is calculated, i needs to be compensated by -2 if Xn is not the last number.
        numLength = countDigit(Xn);
        totalNumLength += numLength;
    }
    // Log
    //cout << endl;
    //cout << "i: " << i << endl;                         // Xn may or may not be the last number that we need the get the answer.
    //cout << "Xn: " << Xn << endl;
    //cout << "totalnumLength: " << totalNumLength << endl;    // totalNumLength would be greater than c.

    // Step 2: find the last number and last digit
    int remain = 0;
    if (totalNumLength > c) {                 //
        int numberOfDigitTobeCutOff = totalNumLength - c;
        remain = cutOff(Xn, numberOfDigitTobeCutOff);
        if (remain == 0) {
            i = i - 2;
            remain = a + b * i;
        }
    }

    // Log:
    ////cout << "remain: " << remain << endl;
    result = remain % 10;
    cout <<result<<endl;
    // resultList.push(result);
    // return result;
}

void output(int result) {
    cout << result << endl;
}

void output(queue<int>& resultList) {
    while (!resultList.empty()) {
        int testCaseResult = resultList.front();                    // first in first out
        cout << testCaseResult << endl;
        resultList.pop();
    }
}

void runTestCase() {
    int a, b;                       // because limit of a,b is 10^6
    long long int c;                // because limit of C is 10^12
    cin >> a >> b >> c;
    runLogic(a, b, c);

}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
    // output(resultList);
}