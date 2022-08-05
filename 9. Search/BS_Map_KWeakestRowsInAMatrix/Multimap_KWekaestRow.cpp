# include <vector>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int, int> strength_row_map;
        for (int row = 0; row< mat.size(); row++){
            //perform binary search
            int left = 0, right = mat[row].size()-1;
            while (left<= right){
                int mid = left + (right-left)/2;
                if (mat[row][mid] == 0)
                    right = mid -1;
                if (mat[row][mid] == 1)
                    left = mid + 1;
            }
            int rowStrength = left;
            strength_row_map.insert({rowStrength, row});
        }
        int count = 1;
        vector<int>result;
        for (auto i : strength_row_map){
            if (count<=k){
                result.push_back(i.second);
                count++;
            }
        }
        return result;
    }
};