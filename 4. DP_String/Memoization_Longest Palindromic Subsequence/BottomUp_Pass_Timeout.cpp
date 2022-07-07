#include<string>
using namespace std;

class Solution {
public:
    int removeCharacter(string s, int left, int right, int removeCount){
        if (left>= right){
            return removeCount;
        }
        if (s[left] == s[right]){
            return removeCharacter(s, left+1, right-1, removeCount);
        }
        if (s[left] != s[right]){
            removeCount = min (removeCharacter(s, left+1, right, removeCount+1),
                               removeCharacter(s, left, right-1, removeCount+1));
        }
        return removeCount;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int left = 0;
        int right = n -1;
        int removeCount = 0;
        removeCount = removeCharacter(s, left, right, removeCount);
        return s.length() - removeCount;
    }
};

int main(){
    Solution sol;
    string s1 = "ababac";
    sol.longestPalindromeSubseq(s1);
}