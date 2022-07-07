#include<vector>
using namespace std;

// improve brute force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {            // overal complexity: O(N^2) but a bit faster
                                                                                        // as the inner loop range is reduced
        vector<int> result;
        for (int i =0; i<nums1.size(); i++){                    // For complexity: O(N)
            vector<int>::iterator it;
            int num = nums1[i];
            it = find(nums2.begin(), nums2.end(), num);         // Find complexity: O(N)
            do {                                                // do while complexity: O(N)
                                                                //==> complexity of find and do while loopO(N+N) ==> O(N)
                it++;
                if (it == nums2.end()) {
                    result.push_back(-1);
                    break;
                }
                int next = *it;
                if (next > num) {
                    result.push_back(next);
                    break;
                }
            }
            while (it !=nums2.end());
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