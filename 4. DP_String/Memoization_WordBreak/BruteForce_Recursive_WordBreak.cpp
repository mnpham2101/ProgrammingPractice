#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std; 

// brute force approach
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        return wordBreakRecur(s, word_set, 0);
    }

    bool wordBreakRecur(string& s, set<string>& word_set, int start) {
        cout<<"--wordBreakRecur-- stringIndex: "<<start<<endl;
        if (start == s.length()) {
            return true;
        }
        cout<<" --For loop Starts--"<<endl;
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            
            cout<<"Substring to search in wordDict "<<word<<endl;
            if (word_set.find(word) != word_set.end() &&  // Step1: Check first condition if left substring is found in wordDict
                wordBreakRecur(s, word_set, end)) {       // Step2: Check second condition if right substring if found in wordDict       
                return true;
            }   
        }
        return false;
    }
};

int main(){
    vector<string> wordDict = {"hello", "world"};
    Solution sol;
    sol.wordBreak("hello", wordDict);
}