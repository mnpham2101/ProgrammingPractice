#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;

// monostack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        stack<int> st;
        unordered_map<int, int> element_nextGreater;
        st.push(nums2[0]);
        for (int i=1; i<nums2.size(); i++){                         //outter for loop: O(N)
            while (!st.empty() && nums2[i] > st.top()){             //while loop: O(N) in worst case
                element_nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // the following comments are equivalent to uncomment codes below
        // for ( int number : nums1){
        //     auto it = element_nextGreater.find(number);
        //     if (it == element_nextGreater.end())
        //         result.push_back(-1);
        //     else
        //         result.push_back(it->second);
        // }

        while (!st.empty()){
            element_nextGreater[st.top()] = -1;
            st.pop();
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