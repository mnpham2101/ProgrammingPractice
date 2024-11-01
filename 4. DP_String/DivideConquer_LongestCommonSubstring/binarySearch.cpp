/* 
1 start with finding the shortest string in the input string array.
2 use binary search to find the common prefix from the shortest string in (1)
    * identify mid point => substring from low -> mid could be the prefix  or mid could be moved up/right. 
    * extract the substring, and compare with all other items in the input strings. 

*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = INT_MAX;
        for (string str : strs) minLen = min(minLen, (int)str.length());
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }
        return strs[0].substr(0, (low + high) / 2);
    }

private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].find(str1) != 0) return false;
        return true;
    }
};