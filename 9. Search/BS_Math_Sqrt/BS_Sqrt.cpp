class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int low = 2, high= x/2;
        while (low<=high){
            int mid = low + (high-low)/2;
            long tmp  = (long) mid*mid;
            if (tmp == x)
                return mid;
            else if (tmp > x)
                high = mid - 1;
            else if (tmp < x)
                low = mid + 1;
        }
        return high;            // the decimal digits are truncated, 
        //only the integer part of the result is returned
        // BUG: return low is wrong.
    }
};