Sol 4: Divide and Conquere Leetcode
class Solution {
private:
    std::vector<std::vector<int>> matrix;
    int target;

    bool searchRec(int left, int up, int right, int down) {
        // this submatrix has no height or no width.
        if (left > right || up > down) {
            return false;
        // cout<<matrix[up][left]<<" "<<matrix[down][right]<<endl;
        // `target` is already larger than the largest element or smaller
        // than the smallest element in this submatrix.
        } else if (target < matrix[up][left] || target > matrix[down][right]) {
            // cout<<matrix[up][left]<<" "<<matrix[down][right]<<endl;
            return false;
        }

        int mid = left + (right - left) / 2;

        // Locate `row` such that matrix[row-1][mid] < target < matrix[row][mid]
        int row = up;
        while (row <= down && matrix[row][mid] <= target) {
            // cout<<matrix[row][mid]<<endl;
            if (matrix[row][mid] == target) {
                return true;
            }
            row++;
        }

        return searchRec(left, row, mid - 1, down) || searchRec(mid + 1, up, right, row - 1);
    }

public:
    bool searchMatrix(std::vector<std::vector<int>>& mat, int targ) {
        // cache input values in object to avoid passing them unnecessarily
        // to `searchRec`
        matrix = mat;
        target = targ;

        // an empty matrix obviously does not contain `target`
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        return searchRec(0, 0, matrix[0].size() - 1, matrix.size() - 1);
    }
};