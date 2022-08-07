# include <vector>
using namespace std;
class Solution {
    vector<int> binarySearchLeft(vector<int>& numbers, int & target, int rightbound){
        // cout<<" Search left of "<<right<<endl;
        vector<int> result = {-1, rightbound+1}; // add 1 because question checker look for 1 indexed array
        int firstNumber = numbers[rightbound];
        int right = rightbound;
        int left= 0;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (numbers[mid] == target - firstNumber && 
                mid != rightbound){     // for corner case
                result[0] = mid+1;      // add 1 because question checker look for 1 indexed array
                return result;
            }
            if (target - firstNumber < numbers[mid])    
                right = mid - 1;                            // search left
            if (target - firstNumber >= numbers[mid])        
                left  = mid + 1;                            // search right
        }
        return result;      // return default=invalid value
    }
    vector<int> binarySearchRight(vector<int>& numbers, int & target, int leftbound){
        // cout<<" Search right of "<<left<<endl;
        vector<int> result = {leftbound+1, -1};
        int firstNumber = numbers[leftbound];
        int left  = leftbound;
        int right = numbers.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            // cout<<"     mid: "<<mid<<endl;
            if (numbers[mid] == target - firstNumber && 
                mid != leftbound){     // for corner case: [1,2,3,4,4,9,56,90] target=8 
                result[1] = mid+1;     // add 1 because question checker look for 1 indexed array
                // cout<<"     1st index: "<<result[0]<<" found 2nd index "<<result[1]<<endl;
                return result;
            }
            if (target - firstNumber < numbers[mid])    
                right = mid - 1;                            // search left
            if (target - firstNumber >= numbers[mid])        
                left  = mid + 1;                            // search right
        }
        return result;      // return default=invalid value
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result = {-1, -1};
        for (int i = 0; i < numbers.size(); i++){
            // cout<<numbers[i]<<" search for: "<<target-numbers[i]<<endl;
            if (target - numbers[i] < numbers[i]){
                result = binarySearchLeft(numbers, target, i);
                if (result[0] != -1)
                    return result;
            }
            if (target - numbers[i] >= numbers[i]){
                result = binarySearchRight(numbers, target, i);
                if (result[1] != -1)
                    return result;
            }   
        }
        return result;
    }
};