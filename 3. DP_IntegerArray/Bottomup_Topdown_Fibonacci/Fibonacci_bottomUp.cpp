#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int fib(int n) {
        vector<int> FibSeq;
        FibSeq.push_back(0);
        FibSeq.push_back(1);
        for (int i = 2 ; i <=n; i ++){
            FibSeq.emplace_back(FibSeq[i-1] + FibSeq[i-2]);
        }
        return FibSeq[n];
    }
};

int main(){
    Solution sol;
    cout<<"Result "<<sol.fib(5)<<endl;
}