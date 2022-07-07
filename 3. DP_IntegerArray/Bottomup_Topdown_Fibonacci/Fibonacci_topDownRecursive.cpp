#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        else return fib(n-1)+fib(n-2);
    }
};

int main(){
    Solution sol;
    cout<<"Result "<<sol.fib(5)<<endl;
}