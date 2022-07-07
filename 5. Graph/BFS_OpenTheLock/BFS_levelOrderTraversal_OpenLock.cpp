class Solution {
private:
    string generateNext(string curr, int wheel, string & target){
        bool roll_backward = false;
        if (10 - curr[wheel] > target[wheel] )
            roll_backward = true;
        if (roll_backward)
            curr[wheel] = curr[wheel] - 1;
        curr[wheel] = curr[wheel] + 1;
        return curr; 
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        // special case:
        if (find(deadends.begin(), deadends.end(), start) != deadends.end())
            return -1;
        int count =0;
        
        queue<string>bfsQueue;
        bfsQueue.push(start);
        deadends.push_back(start);                                      // use deadends as to check visited node
        while (!bfsQueue.empty()){
            int levelSize = bfsQueue.size();
            cout<<"count "<<count<<endl;
            for (int i = 0; i < levelSize; i++){
                string curr = bfsQueue.front();
                cout<<"curr: "<<curr<<endl;
                bfsQueue.pop(); 
                if (curr == target)
                    return count;
                // process neighbors
                for (int wheel = 0; wheel<4; wheel++){                  // for each wheel, mack new combination
                    string next = generateNext(curr, wheel, target);
                    cout<<"     next "<<next<<endl;
                    if ( find(deadends.begin(), deadends.end(), next ) != deadends.end() )  {
                        cout<<"       deadlock or visited"<<endl;
                        continue; 
                    }                        
                    bfsQueue.push(next);
                    deadends.push_back(next);                           // use deadends as to check visited node
                }
            }
            count++;
        }
        
        return -1;      // if bfsQueue is empty => cannot reach the target
    }
};