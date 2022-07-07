#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arrayOne;
        vector<vector<int>> arrayZero;
        int countSubset = 0;
        for (string s: strs){
            int count1 = 0;
            int count0 = 0;
            for (char s: s){
                if (s == '1')
                    count1++;
                if (s == '0')
                    count0++;
            }
            arrayOne.push_back({count1, count0});
            arrayZero.push_back({count0, count1});
        }
        if (n<=m){
            sort (arrayOne.begin(), arrayOne.end());
            int accuOne = 0;
            int accuZero = 0;

            for (int i = 0; i< arrayOne.size(); i++){
                accuOne += arrayOne[i][0];                      // bug here
                accuZero += arrayOne[i][1];
                if (accuOne <=n && accuZero <=m)
                    countSubset++;
                else
                    break;
            }
        }
        if (m<n){
            sort (arrayZero.begin(), arrayZero.end());
            int accuOne = 0;
            int accuZero = 0;

            for (int i = 0; i< arrayZero.size(); i++){
                accuOne += arrayZero[i][1];                     // bug here
                accuZero += arrayZero[i][0];
                if (accuOne <=n && accuZero <=m)
                    countSubset++;
                else
                    break;
            }
        }
        return countSubset;
    }
};

int main(){
    vector<string>strs = {"10","0001","111001","1","0"};
    Solution sol;
    sol.findMaxForm(strs, 5, 3);
}