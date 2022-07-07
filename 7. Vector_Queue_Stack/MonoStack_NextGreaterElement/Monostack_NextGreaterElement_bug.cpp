#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// monostack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        queue<int> stack;
        unordered_map<int, int> element_nextGreater;
        stack.push(nums2[0]);
        for (int i=1; i<nums2.size(); i++){
            // Bug 1: don't compare values in nums2
            // if (nums2[i]>nums2[i-1]){
            //     element_nextGreater[nums2[i-1]] = nums2[i];
            //     stack.pop();
            // }
            // stack.push(nums2[i]);

            // Bug 2 : wrong for TC: nums1={10,2}, nums2={10,2,5,100}, wrong ans = {100,100}
            // if (nums2[i] > stack.front()){
            //     while (!stack.empty()){
            //         element_nextGreater[stack.front()] = nums2[i];
            //         stack.pop();
            //     }
            // }
            // stack.push(nums2[i]);

            // Bug 3: still cannot resolve the issue with stack.back() because stack.pop() will remove the first in item, not the last in item
            int x = stack.back();
            if (nums2[i] > stack.back()){
                while (!stack.empty()){
                    element_nextGreater[stack.back()] = nums2[i];
                    stack.pop();
                }
            }
            stack.push(nums2[i]);
        }

        // the following comments are equivalent to uncomment codes below
        // for ( int number : nums1){
        //     auto it = element_nextGreater.find(number);
        //     if (it == element_nextGreater.end())
        //         result.push_back(-1);
        //     else
        //         result.push_back(it->second);
        // }

        while (!stack.empty()){
            element_nextGreater[stack.front()] = -1;
            stack.pop();
        }
        for ( int number : nums1){
            auto it = element_nextGreater.find(number);
            result.push_back(it->second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    // vector<int>nums1 = {4,1,2};
    // vector<int>nums2 = {1,3,4,2};
    vector<int>nums1 = {10,2};
    vector<int>nums2 = {10,2,5,100};

    sol.nextGreaterElement(nums1, nums2);
}