#include<string>
#include<vector>
using namespace std;


// DP approach + Tree Traversal + Bottom Up + memoization
class Solution {
public:
    // DP equation - Recursive call
    bool isPalindrome(string &s, int left, int right, vector<vector<int>> &cache){
        // memoization , return from cache
        if (cache[left][right] != -1){
            return cache[left][right];
        }
        // base case 1: single character in the middle
        if (left == right){
            cache[left][right] = 1;
            return true;
        }
        // base case 2: 2 same characters
        else if ((right == left + 1) &&
                    (s[left]==s[right])) {
            cache[left][right] = 1;
            return true;
        }
        // base case 3
        else if (left>right)
            return false;
        // other cases, including case 3 characters palindrome such as "aba"
        else if (s[left]==s[right] 
                 && isPalindrome (s, left+1, right-1, cache) 
                 ){
            cache[left][right] = 1;         //true
            return true;
        } 
        // other cases, return false if any recursive result doesn't return true.
        else {
            cache[left][right] = 0;         //false
            return false; 
        } 
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if (s.empty() || n < 1) return "";    
        vector<vector<int>> cache (n, vector<int>(n, -1))  ;  // 2D array[left][right] , need size n! but n*n will do. 
        int left, right = 0; 
        int maxLength = 1;
        int saveLeft=0;
        // run for loop to return result
        for (int left = 0;left <n; left++){
            for (int right = left+1; right <n; right++){
                if (isPalindrome(s, left, right, cache)){
                    if (right - left +1 > maxLength){
                        maxLength = right - left + 1;
                        saveLeft = left;
                    }
                }
            }    
        }
        
        return s.substr(saveLeft, maxLength);
    }
};

int main() {
    Solution sol;
    string s1 = "ababad";           // pass
    string s2 = "cbbd";             // pass
    string s2 = "ababab";           // fail
    
}