#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0;
        vector<int> remain (capacity.size());
        for (int i = 0; i< capacity.size(); i++){
            remain[i}= capacity[i} - rocks[i};
            if (remain[i}==0) count++;
        }
        sort(remain.begin(), remain.end());
        // Log
        // for (int i: remain){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        for (int i : remain){
            additionalRocks -= i;
            cout<<i<<endl;
            if (i!= 0 && additionalRocks >= 0) {
                count++;
                // cout<<"i "<<i<<" additionalRocks "<<additionalRocks<<" count "<<count<< endl;
            } 
            if (additionalRocks < 0) break; 
        }
        return count;
    }
};

int main(){
    Solution sol;

    vector<int> capacity = {91,54,63,99,24,45,78};
    vector<int> rocks = {35,32,45,98,6,1,25};
    int additionalRocks = 17;
    cout<<sol.maximumBags(capacity, rocks, additionalRocks)<<endl;
}