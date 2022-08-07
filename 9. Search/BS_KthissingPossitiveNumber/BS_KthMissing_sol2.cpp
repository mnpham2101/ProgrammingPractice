class Solution {
    public:
    int findKthPositive(int[] arr, int k) {
        // [2, 3], k = 1, result = 1
        // [1, 3, 4] k = 1, result = 2
        // [3, 4] k = 1, result = 5
        
        // check how many numbers missing beween arr[0]
        // it's supposed to be 1, missing = arr[0] - 1 => arr[i] - (i + 1)
        // find a element whose missing is <= k using binary search
        
        // check whether kth missing is at before 0th element || or after end element
        int missing = arr[0] - 1;
        if (missing >= k) {
            return k;
        }
        int missingEnd = arr[arr.length - 1] - arr.length;
        if (missingEnd < k) {
            return arr[arr.length - 1] + (k - missingEnd);
        }
        
        int left = 0, right = arr.length - 1;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            // find missing number vs target
            missing = arr[mid] - (mid + 1);
            if (missing == k) {
                right = mid;
            }
            else if (missing < k) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        
        int missingLeft = arr[left] - (left + 1);
        return arr[left] + (k - missingLeft);
        
    }
}