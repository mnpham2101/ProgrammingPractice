# Description:
Given a non-negative integer c, decide whether there're two integers a and b such that `a^2 + b^2 = c`.

## Example 1:
```
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```

## Example 2:
```
Input: c = 3
Output: false
``` 

## Constraints:
```
0 <= c <= 2^31 - 1
```

# Solution 1: Brute Force
* use double for loop to find value a and b. Time complexity: O(N^2)
* notice the overflow value `a*a` or `b*b` when `a, b` are high. Must use static cast
```
for (int a = 0; (long long) a*a <= c; a++ ){
    for (int b = 0; (long long) b*b<=c;b++){
        if ((long long)(a * a) + (long long)(b * b) == c)
            return true;
    }
}
return false;
```

# Solution 2: Binary Search
```
public class Solution {
    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            System.out.println(a);
            int b = c - (int)(a * a);
            System.out.println(b);
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
    public boolean binary_search(long s, long e, int n) {
        if (s > e)
            return false;
        long mid = s + (e - s) / 2;
        System.out.println("   " + mid);
        if (mid * mid == n)
            return true;
        if (mid * mid > n)
            return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
}
```