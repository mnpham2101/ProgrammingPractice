#include<string.h>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count= 1;                                               // counting start from beginWord
        queue<string>bfsQueue;
        unordered_set<string> wordSet;
        unordered_set<char> possibleTransform;
        for (int i = 0; i<wordList.size(); i++){
            wordSet.insert(wordList[i]);
            for (auto character: wordList[i]){
                possibleTransform.insert(character);
            }
        }
        
        
        // special case
        if (!wordSet.count(endWord)){
            cout<<"endWord is not in wordSet"<<endl;
            return 0;
        }
            
        bfsQueue.push(beginWord);
        while(!bfsQueue.empty()){
            
            // level order counting 
            int n = bfsQueue.size();
            for (int i = 0; i<n; i++){
                string curr = bfsQueue.front();
                cout<<"curr "<<curr<<" "<<count<<endl;
                bfsQueue.pop();
                // create transformation
                for (int position = 0; position<beginWord.length(); position++){
                    string next = curr;
                    for (auto character: possibleTransform){            // limit possible transformation to list of valid characters    
                        next[position] = character;
                        if (next == curr)
                            continue;
                        if (wordSet.count(next)){
                            cout<<"   next "<<next<<endl;
                            bfsQueue.push(next);                        // push in only valid transformation
                            wordSet.erase(next);                        // mark the word as visited
                        }
                        if (next == endWord){
                            cout<<"find endWord "<<next<<" count "<<count<<endl;
                            count++;
                            return count;
                        }     
                    }
                }    
            }
            count++;
        }
        return 0;   // if there is no possible transformation
    }
};