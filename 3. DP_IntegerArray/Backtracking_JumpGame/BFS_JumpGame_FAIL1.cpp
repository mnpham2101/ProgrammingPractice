// BFS solution
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> nextIndexList;
        // construct decision tree
        // Step 1: Make adjacent List of all nodes.
        for (int i = 0; i<n; i++){
            vector<int>nextIndex;
            for (int j=nums[i]; j>0; j--){
                nextIndex.push_back(i+j);
            }
            nextIndexList.emplace(i, nextIndex);
        }
        // perform bfs to check if last index could be reach from 0
        return isValidPathBfs(nextIndexList, 0, n-1);
    }
    bool isValidPathBfs(map<int, vector<int>> nextIndexList, int start, int end){
        // Step 1.1: Make adjacent List of all nodes.
        unordered_set<int> visited;
        // Step 2: Make a queue to process traversing.
        queue<int> bfsQueue;
        // Step 3.1: Add the starting node to queue
        bfsQueue.push(start);
        if (start == end) return true;
        auto node = nextIndexList.begin();
        
        while(!bfsQueue.empty())
        {
            if (bfsQueue.front() == end) {
                return true;
            }
            // Step 3.2: Pop the top node from queue
            bfsQueue.pop();
            // Step 3.3: add neighboring vertices to traversing queue
            if (node != nextIndexList.end()){
                for (auto adjNodes = node->second.begin(); adjNodes !=node->second.end(); adjNodes++ ){
                    if (visited.count(*adjNodes)) {
                        continue;
                    }
                    visited.emplace(*adjNodes);
                    bfsQueue.push(*adjNodes);  
                }
            }
            int nextNode = bfsQueue.front(); 
            node = nextIndexList.find(nextNode);
        }
        return false; 
    }
};

int main(){
    Solution sol; 
    vector<int>nums = {0};
    // vector<int>nums = {0, 1,2,3}
    // vector<int>nums = {1,0,1,0};  
    // vector<int>nums = {2,0};
    // vector<int>nums = {2,3,1,1,4};
    // vector<int>nums = {3,2,1,0,4};
    // vector<int>nums = {5,4,0,2,0,1,0,1,0};
    sol.canJump(nums);
}