#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std; 

// Memoization approach
class Solution {
public:
    map<string, int> cache;
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        // In the cache table, -1 stands for the state not yet reached,
        // 0 for false and 1 for true
        vector<int> cache(s.length(), -1);
        return wordBreakRecur(s, word_set, 0, cache);
    }

    bool wordBreakRecur(string& s, set<string>& word_set, int start, vector<int>&cache) {
        cout<<"---wordBreakRecur--- stringIndex: "<<start<<endl;
        if (start == s.length()) {
            return true;
        }
        
        // step 1: search cache for save value
        if (cache[start] != -1 ) {       // if a cache for a substring was saved, return its value
            cout<<"return cache"<<endl;
            return cache[start];        }; 
        int end;
        string substring;
        // step 2:  make recursive call, find result, save result to cache
        cout<<" --For loop Starts--"<<endl;
        for (end = start + 1; end <= s.length(); end++) {      // make recursive call, topdown
            substring = s.substr(start, end - start);
            if (word_set.find(substring) != word_set.end()) {           // Step2.1: Check first condition if left substring is found in wordDict
                if( wordBreakRecur(s, word_set, end, cache)) {            // Step2.2: Check second condition if right substring if found in wordDict       
                    cout<<"save cache "<<substring<<endl;
                    cache[start]=1;
                    return true;
                }      
            }   
        }
        {
            cout<<"save cache "<<substring<<" false"<<endl;
            return cache[start]=0;
        }
    }
};

int main(){
    vector<string> wordDict = {"hello", "world"};
    Solution sol;
    sol.wordBreak("hello", wordDict);
}