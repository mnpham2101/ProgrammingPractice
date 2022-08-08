#include <vector>
using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        while (left<=right){
            int mid = left + (right-left)/2;
            if (arr[mid]> arr[mid-1] && arr[mid]> arr[mid+1])
                return mid;
            else if (arr[mid]>arr[mid+1])
                right = mid;              // search for peak on the right
            else if (arr[mid]<arr[mid+1])
                left = mid;
        }
        return -1;
    }
};