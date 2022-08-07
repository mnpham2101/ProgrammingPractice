# include <vector>
using namespace std;

class Solution {
private:
    int binarySearchLeft(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] >= target)
                right = mid-1;            // there maybe more target on the left, narrow search to the left
            if (nums[mid] < target)
                left = mid + 1;           // narrow search to the right
        }
        return left; 
    }
    int binarySearchRight(vector<int>& nums, int target, int start){
        int left = start, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                left = mid + 1;            // there maybe more target on the right, narrow search to the right
            if (nums[mid] > target)
                right = mid - 1;             // narrow search to the left     
        }
        return right; 
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        if (nums.size() ==0) 
            return result = {-1,-1};
        int start = binarySearchLeft(nums, target);
        if (start >= nums.size() || 
            nums[start] != target)           // if couldn't find target in 1st bs search   
            return result = {-1,-1};
        int end   = binarySearchRight(nums, target, start);
        result = {start,end};
        return result;
    }
};