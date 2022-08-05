class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        for(int i =0; i<n; i++){
            int find = arr[i] * 2;
            int left = 0,right=n-1;
            
            while(left <= right){
                int mid = left + (right-left)/2;
                if(arr[mid] == find && mid != i){
                    return true;
                }
                else if(arr[mid] > find){
                    right = mid-1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        
        return false;
    }
};