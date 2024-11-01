/*
* recognise that in brute force approach, we have to loop through input array and pick up each string item to compare with earlier prefix. 
* optimize the loop scan by dividing the input string array to subarrays, and compare each pair. 
* Devide method: 
    - choose mid value in the, and divide the input array into subarray, limited by the boudary left-> mid, mid-> right
    - no need to make copies and allocate space for subarray. 
    - recursively call until there are only 1 items in subarray => call it left subarray, do the samething to get rightArray.
* Conquere method: 
    - for each pair of the leftSubarray, and rightSubarray, get the common prefix.
    - it guaranteed that the common prefix returned from subproblem, devided is the common of all pairs of subarrays, as illustrated below: 

    {leetcode, leet, lee, le}
     
    {leetcode, leet}     {lee, le} 

    ans= leet             le

    then {leet, le}
    ans=  le

* Time complexity is still O(m*n) where n are input string size, and m are characters in each string, 
    * best case scenariod is O (minLen * n)
    * 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

private:
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string left, string right) {
        int min = std::min(left.length(), right.length());
        for (int i = 0; i < min; i++) {
            if (left[i] != right[i]) return left.substr(0, i);
        }
        return left.substr(0, min);
    }
};