#include <string>
using namespace std;
/* Given a string, return true if s can be palindrome after deleting at most one character from it.
The string cannot be reorganised.
*/

// Approach: comparing left most and right most character.
// if same, left++, right--, continue comparing the left most, right most characters.
// if fail, shift left++ , compare again.
// if fail, return original string and index left, right, shift right--, compare again
// recursive function loops still base cases reach.
class Solution {
public:
    bool result = false;
    bool comparingCharacter( string & aString, int left, int right, int count){  // potential bug resolved
                                                                               // string is copied in every recursive call => memory issue
                                                                               // solve by using pass by reference
        // base case 1 ==> stop checking palindrom after reaching the middle
        if (left>right) return result;
        // base case 2 ==> stop immediately if we had already remove 2 characters.
        if (count>1){
            return result=false;
        }
        if (aString[left] == aString[right]){
            result = true;
            return comparingCharacter(aString, left+1, right-1, count);
        }
        else {
            result = false;
            count++;
            // remove left character, check if palindrome could be formed
            // remove right character, check if palindrome could be formed
            // note: if we remove left character and check that the palindrome couldn't be formed,
            // we need to return original string and left,right position and count value
            // and start removing right character.
            return ( comparingCharacter(aString, left+1, right, count) || comparingCharacter(aString, left, right-1, count) );
        }
    }
    bool validPalindrome(string aString) {
        int right =aString.length()-1;
        int left = 0;
        int count =0;               // count the character that is deleted
        return comparingCharacter(aString, left, right, count);
    };
};

int main (){
    Solution sol;
    string s1 = "aba";
    string s2 = "tebbem";
    string s3 = "deeee";
    string s4 = "ececabbacec"
    sol.longestPalindrome(s);