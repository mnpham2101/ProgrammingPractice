#include<map>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// unordered map to store array element with respective index
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            if(mp.count(target-nums[i])) // if target - nums[i] value found in map
                return {i,mp[target-nums[i]]};
            else
                mp[nums[i]]=i; 
        }
        return {};
    }
};

int main(){
    Solution sol; 
    vector <int> nums = {1, 3, 2, 5, 1, 3, 2};
    int target = 9;
    sol.twoSum(nums, target);
}