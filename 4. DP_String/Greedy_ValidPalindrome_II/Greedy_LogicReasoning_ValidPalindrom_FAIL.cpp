#include <string>
using namespace std;
/* Given a string, return true if s can be palindrome after deleting at most one character from it.
The string cannot be reorganised.
*/

// Approach: comparing left most and right most character.
// if same, left++, right--, continue comparing.
// if not, shift left++ , compare again. shift right--, compare againt
class Solution {
public:
    bool validPalindrome(string s) {
        int right =s.length()-1;
        int left = 0;
        bool result = false;
        while (left <= right){
            if (s[right] == s[left]){
                result = true;
            }
            else if (s[right] != s[left]) {
                right--;                                // this action is not enought for TC = "deeee", have to perform shifting left and if not success, then shift right.
                if (s[right] == s[left]){
                    result = true;
                }
                else {
                    result = false;
                    break;
                }
            }
            left++;
            right--;
        }
        return result;

    };
};

int main (){
    Solution sol;
    string s = "aaa";
    string s = "aaaAaaaa";
    string s = "aacccbbd";     // acbbdca   => 7
    sol.longestPalindrome(s);
}