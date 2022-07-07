#include<string>
#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> memo;

    int longestPalindromeSubSeq(int left, int right, const string& s) {
        if(left == right) return 1;
        if(left > right) return 0;
        // int& ans = memo[i][j];
        if(memo[left][right] != -1)
            return memo[i][j];
        if(s[left] == s[right]) {
            memo[left][right] = 2 + longestPalindromeSubSeq(left+1, right-1, s);
            return memo[left][right] ;
        }
        // case s[i] != s[j]
        return memo[left][right] = max(longestPalindromeSubSeq(left+1, right, s), longestPalindromeSubSeq(left, right-1, s));
    }

public:
    int longestPalindromeSubseq(string s) {
        const int n = s.length();
        memo.assign(n, vector<int>(n, -1));
        return longestPalindromeSubSeq(0, n-1, s);
    }
};

int main(){
    Solution sol;
    string s1 = "ababac";
    sol.longestPalindromeSubseq(s1);
}