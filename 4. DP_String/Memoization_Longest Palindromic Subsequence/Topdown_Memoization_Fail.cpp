#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeCharacter(string s, int left, int right, int removeCount, vector<vector<int>>&cache ){
        if (cache[left][right] != -1){
            cout<<"return cache "<<left<<" "<<right<<" "<<cache[left][right]<<endl;
            return cache[left][right];
        }
        // base cases
        if (left>= right){
            cache[left][right] = removeCount;                                                       // this saving cache causes failure
            cout<<"base case "<<left<<" "<<right<<" "<<removeCount<<endl;
            return removeCount;
        }
        // recursive cases
        else if (s[left] == s[right]){
            cache[left][right] = removeCharacter(s, left+1, right-1, removeCount, cache);           // this saving cache causes failure
            cout<<"save cache "<<left<<" "<<right<<" "<<cache[left][right]<<endl;
            return cache[left][right];
        }
        else {
            // removeCount = min (removeCharacter(s, left, right-1, removeCount+1, cache),
            //                    removeCharacter(s, left+1, right, removeCount+1, cache));
            removeCount = min (removeCharacter(s, left+1, right, removeCount+1, cache),
                                removeCharacter(s, left, right-1, removeCount+1, cache));
            cout<<"save cache "<<left<<" "<<right<<" "<<cache[left][right]<<endl;
            cache[left][right] = removeCount;                                                       // this saving cache causes failure
            return cache[left][right];
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int left = 0;
        int right = n -1;
        int removeCount = 0;
        vector<vector<int>> cache (n, vector<int>(n,-1)) ;
        removeCount = removeCharacter(s, left, right, removeCount, cache);
        return s.length() - removeCount;
    }
};

int main(){

}