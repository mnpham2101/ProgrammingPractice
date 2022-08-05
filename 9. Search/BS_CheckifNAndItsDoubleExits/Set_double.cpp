class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> nums;
        
        for (int i = 0; i< arr.size(); i++){
            if (nums.find(arr[i]*2) != nums.end() ||
                (arr[i] %2 ==0 && nums.find(arr[i]/2) != nums.end())){
                cout<<arr[i]<<endl;
                return true;
            }
            nums.insert(arr[i]);
        }
        return false;
    }
};