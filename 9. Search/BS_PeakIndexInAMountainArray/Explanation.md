# Description: 
An array arr a mountain if the following properties hold:

* arr.length >= 3
* There exists some i with 0 < i < arr.length - 1 such that:
* `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array arr, return the `index i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in O(log(arr.length)) time complexity.

## Example 1:
```
Input: arr = [0,1,0]
Output: 1
```

## Example 2:
```
Input: arr = [0,2,1,0]
Output: 1
```

## Example 3:
```
Input: arr = [0,10,5,2]
Output: 1
``` 

## Constraints:
```
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
```

# Solution: Binary Search
* *Note*: 
    * This kind of array is `Bitonic Array`
    * there is only 1 peak in the array; 
    * There is no flat peak, but there maybe a "flat-slope"
* **Brute-Force Solution**: linear search through the array, searh for max value, and break when the value start to decrease.
    * Worst case scenario: the peak is at the end of the array. Thus time complexity is `O(n)`
* **Binary search solution**: optimizes the performance by making time complexity to `O(logN)`. 
## Algorithm:
* set `left = 0`, `right = array.length - 1`, `mid = left + (right - left)/2`
* loop while (left < = right)
    * if `array[mid+1] > array[mid]`: search right for peak
    * if `array[mid+1] <= array[mid]`: search left for peak
    * return `result=mid` if `array[mid-1]<array[mid]>array[mid+1]`
        * there is overflow issue because the array size min is 3.