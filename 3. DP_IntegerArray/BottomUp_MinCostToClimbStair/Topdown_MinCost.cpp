#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>

class Solution {
private:
    int costCalc(vector<int>&cost, int step, vector<int>& cache){
        // cout<<"Step: "<<step<<endl;
        int n= cost.size();
        // base
        if (step >= n){
            // cout<<step<<"  "<<0<<endl;
            return 0;
        }
        if (step != -1 && cache[step] != -1)
            return cache[step];

        if(step == -1){
            int takeOneStep  = costCalc(cost, step+1, cache);
            int takeTwoSteps = costCalc(cost, step+2, cache);
            // cout<<takeOneStep<<" "<<takeTwoSteps<<endl;
            return min(takeOneStep, takeTwoSteps); 
        }

        // recurrence:
        int takeOneStep  = costCalc(cost, step+1, cache);
        int takeTwoSteps = costCalc(cost, step+2, cache);
        // cout<<" "<<takeOneStep<<" "<<takeTwoSteps<<endl;
        return cache[step] = cost[step] + min(takeOneStep, takeTwoSteps);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size()+1,-1);
        return costCalc(cost, -1, cache);
    }
};

int main(){
    std::vector<int> cost = {10, 15, 20};
    std::cout << "Minimum cost: " << minCostClimbingStairs(cost) << std::endl;
    return 0;
}