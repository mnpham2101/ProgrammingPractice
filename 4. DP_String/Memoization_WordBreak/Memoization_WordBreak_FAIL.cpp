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
        return wordBreakRecur(s, word_set, 0);
    }

    bool wordBreakRecur(string& s, set<string>& word_set, int start) {
        cout<<"---wordBreakRecur--- stringIndex: "<<start<<endl;
        if (start == s.length()) {
            return true;
        }
        
        // step 1: search cache for save value
        int end = start + 1;
        string leftSubstring = s.substr(start, end - start);
        cout<<"Substring to search in wordDict "<<leftSubstring<<endl;
        if (cache.find(leftSubstring) != cache.end() ) {       // if a cache for a substring was saved, return its value
            cout<<"return cache "<<leftSubstring<<endl; 
            return true;
        }; 
        
        // step 2:  make recursive call, find result, save result to cache
        cout<<" --For loop Starts--"<<endl;
        for (int end = start + 1; end <= s.length(); end++) {      // make recursive call, topdown
            if (word_set.find(leftSubstring) != word_set.end()) {     // Step2.1: Check first condition if left substring is found in wordDict
                
                if( wordBreakRecur(s, word_set, end)) {       // Step2.2: Check second condition if right substring if found in wordDict       
                    cout<<"save cache "<<leftSubstring<<endl;
                    cache[leftSubstring]=1;
                    return true;
                }      
            }   
        }
        return cache[leftSubstring]=0;
    }
};

int main(){
    vector<string> wordDict = {"hello", "world"};
    Solution sol;
    sol.wordBreak("hello", wordDict);
}