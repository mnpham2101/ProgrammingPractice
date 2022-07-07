#include <string>
#include <map>
using namespace std;
/* Given a string, find a longest palindrom that can be made from the string
*/
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> characterCount;
        int result = 0;
        // Step 1: count all characters by their frequency of appearance
        for (char i : s){
            characterCount[i]++;
        }

        for (auto it = characterCount.begin(); it != characterCount.end(); it++){
            int count = it->second;
            // Step 2: add character that count are even to palindrome
            if (count % 2 == 0) {                   // fail TC = aaaAaaaa
                result += count;
            }
            // Step 3: consider to add a single character in the middle
            // a palindrome would even count = even if there is no unique character in the middle.
            // if character count is odd => make decision to use only 1 character in the middle.
            if (count % 2 == 1 && result %2 ==0){        // Observation 2.1
                result ++;
            }
            if (count % 2 == 1 && result %2 == 1){       // Observation 2.2
                result +=count-1;
            }
        }

        return result;
    }
};

int main (){
    Solution sol;
    string s = "aaa";
    string s = "aaaAaaaa";
    string s = "aacccbbd";     // acbbdca   => 7
    sol.longestPalindrome(s);
}