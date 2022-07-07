# Description

An influencer wants to use his sponsored goods while maximizing his preferences. The preferences are integer values in an array `D` of size `N`. He has two choices:
- use only 3 goods and find maximum preferences. The original code implements this choice.
- use any number of goods and find maximum preferences. The goods are selected in a row (subarray of array `D`). Modify the original code to implement this choice. 

# Approach: 
- This problem is the same as problem "Maximum subarray" in leetcode https://leetcode.com/problems/maximum-subarray/ 
- Use `Kadane's algorithm`: add the item to the sum only if sum is positive, reset if it is negative. Compared sum with earlier save maxSum. Return result as maxSum. 
- Note: 
  ```
  if (D[i] < sum + D[i])  
  it is the same as sum >0
  ```
## Algorithm
* Note that double for loop could do the job but it is time-limited for large data set.
```
int maxSum=nums[0];
for (int i = 0; i<nums.size(); i++){
    int sum=0;
    for (int j=i; j<nums.size(); j++){
        sum +=nums[j];
        if (sum>maxSum) {
            maxSum = sum;       //maxSum could still be negative
        }
        if (sum<0) {
            i =j;        // set the subarray starting from j
            break;       // dont count sum if sum is negative
        }
    }
}
```
* A single for loop reduce time complexity
```
for (int i = 1 ; i< N; i++){
    // sum = max(nums[i], sum+nums[i]);
    if (sum>0)                //same as if (nums[i]<sum[0]+nums[i])
        sum += D[i];
    else
        sum = D[i];
    if (sum>maxSum) {
        maxSum = sum;
    }
}
```