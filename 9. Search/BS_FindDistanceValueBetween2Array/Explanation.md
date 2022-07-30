# Description:

Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as **the number of elements in arr1** such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d. 

In other words: `if |arr1[i]+ arr2[j]| > d, count++`; 

## Example 1:
```
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
```

## Example 2:
```
Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2
```
## Example 3:
```
Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1
``` 

## Constraints:
```
1 <= arr1.length, arr2.length <= 500
-1000 <= arr1[i], arr2[j] <= 1000
0 <= d <= 100
```

# Solution - Brute Force
* double for loop presents a brute force search:
```
int count = 0;
for (int i =0 ; i < arr1.size(); i++){
    bool isDistance = true;
    for (int j = 0; j <arr2.size(); j++){                       // linear search on inner for loop
        cout<<abs(arr1[i] - arr2[j]) <<endl;
        if (abs(arr1[i] - arr2[j]) <= d){              
            isDistance = false;
            break;
        }                     
    }               
    if (isDistance){
        count++;
    } 
}
return count;
```
* the complexity is O(n^2) where exhaustive search on second linear search is require to affirm the condition `isDistance == true` . For `isDistance==false` a break happens, and there is no exhaustive search.
* inner for loop could be improved with binary-search method.

# Solution - Binary search
* Binary search attempts to optimize the search time complexity of inner for loop in brute force solution. 
* Instead of searching through the entire arr2 for true case, we search in half of the array: 
    * `if arr[1]> arr[2]` search the half left of the arr2. 
        * The reason is: 
        ```
        if abs(arr[1] - arr2[2]) <d then:
            arr[1] - arr[2]  < d       therefore   arr[1]   < arr[2] + d 
            arr[1] - arr[2]  > -d      therefore   arr[1]   > arr[2] + d 
        ```
        * Therefore, we use binary search algorithm to search half of the arr2 to find the condition where `arr[1] - arr[2] <=d` may happen
        * if it happens, then return false, and don't increment `count`
    * `if arr[1]< arr[2]` search the half right of the arr2.  