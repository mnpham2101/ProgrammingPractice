# include <vector>
using namespace std; 

class Solution {
public:
    bool isValidDistance(int & num, vector<int> &arr2, int &d){
        int low = 0, high = arr2.size();
        while (low<= high){
            int mid = low + (high - low)/2;
            int tmp = abs(num - arr2[mid]);
            if (tmp <=d)                        
                return false;                       // there is an element that: |arr1[i]-arr2[j]| <= d, don't count in result
            // binary search condition based on arr2[mid]
            else if ( arr2[mid] > num)             // arr1[i] - arr2[j] < 0     
                high = mid -1; 
            else if (arr2[mid] < num)              // arr1[i] - arr2[j] > 0   
                low = mid + 1;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        sort(arr2.begin(), arr2.end());             // sort arr2 ascendingly
        for (int i =0 ; i < arr1.size(); i++){
            bool isDistance = isValidDistance(arr1[i], arr2, d);                // running binary search      
            if (isDistance){
                count++;
            } 
        }
        return count;
    }
};