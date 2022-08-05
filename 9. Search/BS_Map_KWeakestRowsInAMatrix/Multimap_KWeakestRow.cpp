#include <vector>
using namespace std;

class Solution {
public:
    // brute-force + map O(m*n + mlogm)
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int, int> strength_row_map;
        for (int row = 0; row< mat.size(); row++){
            int rowStrength = 0;
            // cout<<"row"<<row<<" rowStrength ";
            for (int col=0; col<mat[row].size(); col++){
                rowStrength += mat[row][col];
            }
            // cout<< rowStrength<<endl;
            strength_row_map.insert({rowStrength, row});
        }
        vector<int>result;
        int count = 1;
        for(auto i : strength_row_map){
            if (count <=k){
                result.push_back(i.second);
                count++;
            }
        }    
        return result;
    }
};