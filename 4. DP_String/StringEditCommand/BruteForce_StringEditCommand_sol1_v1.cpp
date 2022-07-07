#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string S;
    string C;
    vector<string> resultString;
    void Input() {
        cin >> S;
        cin >> C;
    }
    // correct 2/10 Test Case,
    void Solve() {
        resultString.resize(S.length()+1);            // S.length() stores S string + cursor

        int cursor = 0;

        for (char c : S) {
            resultString[cursor++] = c;          // assign value then increment i
            // resultString[++i] = " ";
        }
        // resultString[cursor] = " ";           // add a space for the last position of the cursor

        for (char c : C) {
            if (c == 'R' && cursor != resultString.size()-1) {
                cursor++;
            }
            else if (c == 'R' && cursor == resultString.size()-1) {     // must add this condition, otherwise, the last condition is hit, and `R` is added
                continue;
            }
            else if (c == 'L' && cursor != 0) {
                cursor--;
            }
            else if (c == 'L' && cursor == 0) {      // must add this condition, otherwise, the last condition is hit, and `L` is added
                continue;
            }
            else if (c == 'B' && cursor == 0) {      // cannot delete a character if cursor at the begining position
                                                     // must add this condition, otherwise, the last condition is hit, and `B` is added
                continue;
            }
            else if (c == 'B' && cursor != 0 && cursor - 1 >= 0) {
                cursor--;                                                    // cursor i should be always on the right of character => decrement i to move to character to be deleted position
                resultString.erase(resultString.begin() + cursor);

            }
            else {
                string tmp(1, c);            // convert character c to string using string class fill constructor. Ref: https://www.techiedelight.com/convert-char-to-string-cpp/
                resultString.insert(resultString.begin() + cursor, tmp);         // sise is increased
                cursor++;                                                        // therefore, it is safe to increment i and access resultString[i]
                                                                            // increment i because after adding a character, the cursor moves to the right of the added character.
            }
        }
    }

    void Output() {
        for (int i = 0; i < resultString.size(); i++) {
            cout << resultString[i];
        }
    }
};

int main() {
    Solution sol;
    sol.Input();
    sol.Solve();
    sol.Output();
}