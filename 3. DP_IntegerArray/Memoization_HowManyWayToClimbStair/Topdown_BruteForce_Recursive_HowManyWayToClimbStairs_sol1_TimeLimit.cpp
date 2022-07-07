#include <iostream>

using namespace std;

// top down solution, brute force, traverse every branch, going deeper first.
// this solution causes Time Limit Exceed
class Solution {
    public:
    int climbStairs(int n) {
        int counter = 0;
        counter += climbStairs(0,n, 1) + climbStairs(0,n, 2);
        cout<<"Result: "<<counter<<endl;
        return counter;
    }

    int climbStairs(int startingStep, int endStep, int stepSize){
        cout<<" -- start "<<startingStep<<" -- end "<<endStep<<" -- stepSize "<<stepSize<<endl;
        startingStep = startingStep + stepSize;
        cout<<"nextstep "<<startingStep<<endl;
        if (startingStep == endStep){
            cout<<"add 1"<<endl;
            return 1;
        }
        else if (startingStep<endStep) {

            return climbStairs(startingStep, endStep, 1) + climbStairs(startingStep, endStep, 2);
        }
        else {
            cout<<"not reaching end"<<endl;
            return 0;
        }
    }
};

int main() {
    Solution sol;
    sol.climbStairs(35);
}