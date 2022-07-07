#include<string>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;

queue<int> resultList;

void input() {

}

void runLogic() {
    resultList.push(5);

}



void output(queue<bool>& resultList) {
    while (!resultList.empty()) {
        bool testCaseResult = resultList.front();                    // first in first out
        if (testCaseResult == true) cout << "NOT CHEATER" << endl;
        else cout << "CHEATER" << endl;
        resultList.pop();
    }
}

// this function is wrong because it only returns the left most, right most value; 
// will not work for case aaxcd and aaycd where both `aa` and `cd` are needed to be returned
// logic will find lenght = 2 and return str2 index = 2 => wrong common substring as `ax`
void findSubstringLength(string& str1, string& str2, int& L, int& F, int& str1Index, int& str2Index, int& commonSubstringLength) {
    if (commonSubstringLength == F) return; 
    if (str1Index > L - 1 || str2Index > L - 1) return; 
    else if (str1[str1Index] == str2[str2Index]) {
        str1Index++;
        str2Index++;
        commonSubstringLength++;
        findSubstringLength(str1, str2, L, F, str1Index, str2Index, commonSubstringLength);
    }
    else if (str1[str1Index] != str2[str2Index]) {
        str1Index++;
        str2Index = 0;
        commonSubstringLength = 0;
        findSubstringLength(str1, str2, L, F, str1Index, str2Index, commonSubstringLength);         
    }
}

// return by ref commonSubstring of 2 string
// only needs to find upto L characters for F substring
void findCommonSubstring(string str1, string str2, int L, int F,  map<string, int>& commonSubstring) {
    int commonSubstringLength = 0;
    int str1Index = 0; 
    int str2Index = 0;

    // this function is wrong because it only returns the left most, right most value; 
    // will not work for case aaxcd and aaycd
    findSubstringLength(str1, str2, L, F, str1Index, str2Index, commonSubstringLength);
    // will not work because if we have aaxcd , aaycd, bbzcd, then common substrings are {"aa",2}, {"cd",3}
    string common = str1.substr(commonSubstringLength - str2Index + 1, commonSubstringLength);      
    commonSubstring[common] += 2;     // add 2 since it is a pair of 2.  
}

void runTestCase() {
    
    int n, L, F;
    cin >> n >> L >> F;

    string str;
    vector<string> stringList(n);

    for (int i = 0; i < n; i++) {
        cin >> str;
        stringList[i] = str;
    }

    map<string, int> commonSubstring;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)                                                 // O(n^2) = 500^2
            findCommonSubstring(stringList[i], stringList[j], L, F, commonSubstring);   // see code on internet 
    }
    
    int ans = 0;
    for (auto it = commonSubstring.begin(); it != commonSubstring.end(); it++) {
        // will not work because if we have common substrings are {"aa",2}, {"cd",3}
        // we need to get the max value 3 and not add 2
        ans += (it->second) * (it->second - 1) / 2;
    }
    
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
    // output(resultList);
}