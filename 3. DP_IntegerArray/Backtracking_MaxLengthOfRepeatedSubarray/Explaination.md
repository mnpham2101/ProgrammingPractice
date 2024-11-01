# Approach 1: 
nums1 = [1,2,3,2,1],       1 
nums2 = [3,2,1,4,7]        3 2 1
1) queue method: 
    push nums1 to queue
    search for each item in nums2, search for match in nums1, if match , then push from queue, and compare, update count. 
    What happen if it doesn't match. 
2) recursive
i=0                        1                       no pick
i=1                    2       nopick         2          no pick
i=2                3      np     3   np    3    np     
i=...           return 1

     checkSameVal(nums1, nums2, index, take)
        auto it = finds(nums2.begin -> end, nums[index])  (problematic because there could be repetition)
        if (it != nums2.end)
          count1 += checkSameVal(nums1, num2, index+1, it+1, take= true)
        else
          count2 = checkSameVal(nums1, num2, index+1, take= flase);
           count = max(count1, count2)
[1 2 3 1 3 4 5 6]
[1 2 1 3 4]

3) iteration. 

3) iteration on 2D matrix  row = nums1.size()+1, col = nums2.size()+1
    1 2 3 2 1
  3 0 0 1 0 0
  2 0 1 0 2 0
  1 1 0 0 0 3
  3 0 0 1 0 0
  4 0 0 0 0 0 

if (nums[col] == nums[row]) then  matrix[row][col] = 1 + adjDiagonal = 1 + matrix[row-1][col-1]

4) slicing windows:
