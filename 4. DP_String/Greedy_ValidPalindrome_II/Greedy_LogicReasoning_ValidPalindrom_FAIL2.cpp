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
    bool comparingCharacter( string aString, int left, int right){
        if (aString[left] == aString[right]){
            return true;
        }
        else return false;
    }
    bool validPalindrome(string aString) {
        int right =aString.length()-1;
        int left = 0;
        bool result = false;
        int count =0;               // count the character that is deleted
        while (left <= right){
            if (count>1){
                return false;
            }
            if (comparingCharacter(aString, left, right)){
                left++;
                right--;
                result = true;
                continue;
            }
            else if (comparingCharacter(aString, left, right-1)) {          // if removing right character first and keep on checking, we have false value for TC: "ececabbacec"
                left++;
                right=right-2;
                count++;
                result = true;
                continue;
            }
            else if (comparingCharacter(aString, left+1, right)) {         // for TC: "ececabbacec" we could remove left character e first and get true value
                                                                           // ==> shifting in sequential order doesn't help,
                                                                           //need to make recursive call to return the original string, and start removing left character
                left = left+2;
                right--;
                count++;
                result = true;
                continue;
            }
            else return false;
        }
        return result;
    };
};

int main (){
    Solution sol;
    string s1 = "aba";
    string s2 = "tebbem";
    string s3 = "deeee";
    string s4 = "ececabbacec"
    sol.longestPalindrome(s);
}