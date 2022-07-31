// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // binary search
    int firstBadVersion(int n) {
        // int left = 1, right = n;
        // while (left < right){
        //     int mid = left + (right - left)/2;
        //     if (isBadVersion(mid))              // mid may or may not be the first bad version
        //         right = mid;                     // dont search the higher version from mid+1
        //     else if (!firstBadVersion(mid))      // bug    
        //         // mid is not the bad version, all the versions before mid are good
        //         left = mid + 1;                  // search the higher versions
        // }
        // return left;
        
        
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {                             // result without bug
                left = mid + 1;
            }
        }
        return left;
    }
};