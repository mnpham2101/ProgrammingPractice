#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // bool result = false; 
        unordered_map<char, int> check;
        int index = 0;
        for (char c : s){
            cout<<"index"<<index<<" "<<c<<endl;
            if (!check.count(c)){        
                check[c]= s.find(c);
                cout <<"1st index " <<check[c]<<endl;
                index++;
            }
            else{
                cout <<"1st index " <<check[c]<<endl;
                cout <<"2nd index " <<index<<endl;
                int distanceBwCharacter  = index - check[c]-1;
                cout<<"update check[c] "<<distanceBwCharacter<<endl;
                if (distance[(int)c - 97] != distanceBwCharacter)
                    return false;
                index++;
            }
        }
        return true;
    }
};