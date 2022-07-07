#include<vector>
using namespace std;

// brute force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums2.begin(), nums2.end(), greater<int>());

        vector<int> result;
        for (int i =0; i<nums1.size(); i++){                            // O(N^2)
            bool found = false;
            int number = nums1[i];
            for (int j = 0; j<=nums2.size(); j++){
                if (j == nums2.size())
                    result.push_back(-1);
                else if (nums2[j]==number){
                    found = true;
                    continue;
                }
                else if (nums2[j] > number && found == true){
                    result.push_back(nums2[j]);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};
    sol.nextGreaterElement(nums1, nums2);
}