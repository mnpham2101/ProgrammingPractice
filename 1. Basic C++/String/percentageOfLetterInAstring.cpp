#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int result = 0, count=0;
        for (char c : s){                       // how to extract characters from a string
            if (c == letter){
                count++;
            }
        }
        result = count*100/s.length();
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.percentageLetter("hellllllo", 'l');
}