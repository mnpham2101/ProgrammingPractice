#include <string>
using namespace std;

// TRUE if there is no evidence of failure...
class Solution {
 public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while (i < j && !isalnum(s[i]))  // skip if encounter a space
        i++;
      while (i < j && !isalnum(s[j]))  // skip if encounter a space
        j--;
      if (tolower(s[i]) != tolower(s[j])) // if a single character on left, right doesn't match 
                                          // return false
        return false;
    }
    return true;
  }
};

int main() {
    Solution sol; 
    sol.isPalindrome("A man, a plan, a canal: Panama");
}