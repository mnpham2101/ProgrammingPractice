/*

1   4  7 11 15
2   5  8 12 16
3   6  9 16 22
10 13 14 17 24
18 21 23 26 30

if target = 30, 

first search the left columns, 1st row: 
7 11 15
then search the bottom row, 1 column
3 10 18
continuous search:
8 12 16
6 13 21
16 22
14 23
17 24
17 26

*/

// Sol3: binary search, leetcode support
class Solution {
private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, bool vertical) {
        int lo = start;
        int hi = vertical ? matrix[0].size() - 1 : matrix.size() - 1;

        while (hi >= lo) {
            int mid = (lo + hi) / 2;
            if (vertical) { // searching a column
                if (matrix[start][mid] < target) {
                    // cout<<matrix[start][mid] <<" ";
                    lo = mid + 1;
                } else if (matrix[start][mid] > target) {
                    // cout<<matrix[start][mid] <<" ";
                    hi = mid - 1;
                } else {
                    return true;
                }
            } else { // searching a row
                if (matrix[mid][start] < target) {
                    // cout<<matrix[mid][start] <<" ";
                    lo = mid + 1;
                } else if (matrix[mid][start] > target) {
                    // cout<<matrix[mid][start] <<" ";
                    hi = mid - 1;
                } else {
                    return true;
                }
            }
        }
        cout<<endl;
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // an empty matrix obviously does not contain `target`
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        // iterate over matrix diagonals
        int shorterDim = min(matrix.size(), matrix[0].size());
        for (int i = 0; i < shorterDim; i++) {
            bool verticalFound = binarySearch(matrix, target, i, true);
            bool horizontalFound = binarySearch(matrix, target, i, false);
            if (verticalFound || horizontalFound) {
                return true;
            }
        }

        return false;
    }
};