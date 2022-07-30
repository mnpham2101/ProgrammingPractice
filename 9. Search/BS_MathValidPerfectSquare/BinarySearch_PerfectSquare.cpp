class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num<2)
            return true;
        long left = 2, right = num/2, mid, guessSquare;
        while (left<=right){
            mid = left + (right - left)/2;
            guessSquare = mid*mid;
            if (mid* mid == num){
                return true;
            }
            if (guessSquare > num)
                right = mid - 1;
            else
                left = mid +1;
        }
        return false;
    }
};