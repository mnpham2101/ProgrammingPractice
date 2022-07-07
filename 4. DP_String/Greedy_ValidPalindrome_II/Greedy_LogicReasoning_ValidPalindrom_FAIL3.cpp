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
        else {
            // remove left character, check if palindrome could be formed
            // remove right character, check if palindrome could be formed
            // bug: upon finishing with removing left character, the left value is not saved for continuous check, TC "deeee" fails
            // note: if we remove left character and check that the palindrome couldn't be formed, we need to return original string (left, right)
            // and start removing right character.
            return ( comparingCharacter(aString, left, right-1) || comparingCharacter(aString, left+1, right) );
        }
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