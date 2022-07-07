#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Tree traversing + memoization
class Solution {
public:
    
    int turnScore (vector<int>piles, int left, int right, int turn, vector<vector<int>>&cache){
        // base case
        if ((left == right) && (turn % 2 == 0)){   
            cache[left][right] = piles[left];                       // memoization - save cache 
            return + piles[left];
        }
        else if ((left == right) && (turn % 2 != 0)){      
            cache[left][right] = - piles[left];                     // memoization - save cache 
            return - piles[left];
        } 
        // memoization - retrieve cache 
        if (cache[left][right] !=INT_MAX ){
            cout<<"return cache["<<left<<"]["<<right<<"]="<<cache[left][right]<<endl;
            return cache[left][right];
        }  
        // 
        else if ((left < right) && (turn %2 == 0)){           
            int a = piles[left] + turnScore(piles, left+1, right, turn+1, cache);     
            int b = piles[right] + turnScore(piles, left, right-1, turn+1, cache);
            int c = max(a,b);          
            cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
            cache[left][right] = c;                                          // memoization - save cache 
            return c;
        } 
        else if ((left < right) && (turn %2 != 0)){
            int a = -piles[left] + turnScore(piles, left+1, right, turn+1, cache);
            int b = -piles[right] + turnScore(piles, left, right-1, turn+1, cache);
            int c = min(a,b);  
            cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
            cache[left][right] = c;                                            // memoization - save cache 
            return c;
        }
        else
            return 0;
    }

    bool stoneGame(vector<int> &piles)
    {
        int left = 0;
        int right = piles.size()-1;
        int n = piles.size();
        // int previousScore =0;
        int turn = 0;
        vector<vector<int>> cache (n,vector<int>(n, INT_MAX));
        int score = turnScore(piles, left, right, turn, cache);        // total score at top of tree
        
        if (score>=0) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    vector<int> piles1 = {5,3,4,5};
    vector<int> piles2 = {3,7,2,3};          // TC pass
    vector<int> piles3 = {3,2,10,4};         // TC fails ==> if Alice picks the lower value 3 instead of 4
                                            // ==> Alice will win. 
    cout<<sol.stoneGame(piles1)<<endl;
}
