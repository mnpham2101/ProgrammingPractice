#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int, int> value_position;
        for(int i = 0; i<nums2.size(); i++){
            value_position[nums2[i]] = i;
        }

        // overall complexity: O(N*logN)
        for (int i=0; i<nums1.size(); i++){                     // outer for loop: O(N)
            int number = nums1[i];
            auto it = value_position.find(number);              // O(logN)
            int nextGreater_position;
            for (nextGreater_position = it->second+1; nextGreater_position < nums2.size(); nextGreater_position++){         // O(N)
                if (nums2[nextGreater_position]>number){
                    result.push_back(nums2[nextGreater_position]);
                    break;
                }
            }                                                   // overal complexity for find() and inner for loop: O(logN + N) ==> O(logN)
            if (nextGreater_position == nums2.size()){
                result.push_back(-1);
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