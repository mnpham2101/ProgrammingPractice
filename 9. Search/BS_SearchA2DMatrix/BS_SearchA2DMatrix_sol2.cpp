#include<vector>
#include<iostream>
using namespace std;

class Solution {
private:
    bool searchRow(vector<vector<int>>& matrix, int & target, int & row){
        if (matrix.size() == 1){
            // cout<<"only 1 row"<<endl;
            return matrix[0][0] <= target;
        }
        int top=0, bottom = matrix.size()-1;
        while(top<=bottom){
            int mid = top + (bottom - top)/2;
            cout<<"row "<<mid<<endl;
            int rowLength = matrix[mid].size()-1;
            if(matrix[mid][0]<= target && matrix[mid][rowLength]>=target){
                cout<<"found row: "<<row<<endl;
                row = mid;
                return true;
            }
            else if(matrix[mid][0] < target){
                // cout<<"     top row "<<mid<<endl;
                top = mid+1;      // search further down
            }
            else if(matrix[mid][0] > target){
                // cout<<"     bottom row "<<mid<<endl;
                bottom = mid-1;   // search further up
            }
        }
        return false;
    }
    bool searchTargetInRow(vector<vector<int>>& matrix, int & target, int & row){
        cout<<"searchTargetInRow "<<row<<endl;
        if (matrix[row].size() == 1){
            return matrix[row][0] == target;
        }
        int left=0, right = matrix[row].size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            cout<<"mid "<<mid<<endl;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target){
                right = mid - 1;
                cout<<"     search right "<<right<<endl;
            }
            else if (matrix[row][mid] < target){
                left = mid + 1;
                cout<<"     search left "<<left<<endl;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        if (!searchRow(matrix, target,row))
            return false;
        else
            return searchTargetInRow(matrix,target,row);
    }
};