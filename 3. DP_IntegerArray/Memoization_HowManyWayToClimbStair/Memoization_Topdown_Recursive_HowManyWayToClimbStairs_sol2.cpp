#include <iostream>
#include <vector>
#include <map>

using namespace std;

// top down solution, saving result to cache
class Solution {
    public:
    int climbStairs(int n) {
        vector<int> cache(n,0);
        return climbStairsRecursive(1,n, cache) + climbStairsRecursive(2,n, cache);
    }


    int climbStairsRecursive(int startingStep, int endStep, vector<int> &cache){
        cout<<" -- start "<<startingStep<<" -- end "<<endStep<<endl;

        // base case 1
        if (startingStep == endStep){
            cout<<"add 1"<<endl;
            return 1;
        }
        // recursive case
        else if (startingStep<endStep) {
            if (cache[startingStep] > 0) {       // memoization, return cache
                return cache[startingStep];
            }
            else {
                // memoization, save cache
                cache[startingStep] = climbStairsRecursive(startingStep+1, endStep, cache) + climbStairsRecursive(startingStep+2, endStep, cache);
                //Log
                cout<<"cache["<<startingStep<<"]="<<cache[startingStep]<<" ";
                cout<<endl;
                return cache[startingStep];
            }

        }
        // base case 2
        else {              // case startingStep > endStep
            return 0;
        }
    }
};

int main() {
    Solution sol;
    int result = sol.climbStairs(5);
    cout<<"Result "<<result<<endl;
}