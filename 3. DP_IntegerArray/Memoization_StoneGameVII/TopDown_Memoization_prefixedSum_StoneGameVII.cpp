#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Tree traversing + memoization
class Solution {
public:
    
    int turnScore (vector<int>&piles, int left, int right, int turn, vector<vector<int>>&cache, vector<int>&prefixSum){
        cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
        int playerScore = 0, a=0,b=0;
        // base case
        if (left>right) return 0;           // must have because if not, for case left=0, right=-1, the next if(cache[left][right]) returns segfault 
        // if (left== right)                // no neccessary since it is included in recursive case      
        // memoization - return via cache
        if (cache[left][right] !=INT_MAX ){
            cout<<"return cache["<<left<<"]["<<right<<"]="<<cache[left][right]<<endl;
            return cache[left][right];
        }
        // starting, no one play yet.
        if (turn == 0){                                                             
            
            int a = turnScore(piles, left, right-1, turn+1, cache, prefixSum);
            int b = turnScore(piles, left+1, right, turn+1, cache, prefixSum);            
            int c = max(a,b);
            // cout<<"sum:"<<sum<<" a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
            return c;
        }  
        
        // both players scores when left <= right 
        // input left, right indicates the range of remaining cards after the player removes a card
        // score = sum (left -> right) + turnResult (leftNext, rightNext, nextTurn)
        else if ((left <= right) && (turn %2 == 0)){                                 // Bob plays      
            playerScore = prefixSum[right+1]-prefixSum[left];                     // player score in current turn
            
            a = turnScore(piles, left+1, right, turn+1, cache, prefixSum);  
            b = turnScore(piles, left, right-1, turn+1, cache, prefixSum);                                                       
            cache[left][right] = -playerScore + max(a,b);                        // max(a,b) is the score of the next player, Alice 
            cout<<"return value recursively"<<endl;
            cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            cout<<"playerScore:"<<playerScore<<endl;
            cout <<"total "<< cache[left][right] <<endl;
            return cache[left][right];
        } 
        else if ((left <= right) && (turn %2 != 0)){                                 // Alice plays
            playerScore = prefixSum[right+1]-prefixSum[left];                           // player score in current turn
            a = turnScore(piles, left+1, right, turn+1, cache, prefixSum);  
            b = turnScore(piles, left, right-1, turn+1, cache, prefixSum);                                                   
            cache[left][right] = playerScore + min(a,b);                                // min(a,b) is the score of the next player, Bob  
            cout<<"return value recursively"<<endl;
            cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            cout<<"playerScore:"<<playerScore<<endl;
            cout <<"total "<< cache[left][right] <<endl;
            return cache[left][right];
        }
        else
            return 0;
    }

    int stoneGameVII(vector<int> &piles)
    {
        int left = 0;
        int right = piles.size()-1;
        int n = piles.size();
        int turn = 0;
        vector<vector<int>> cache (n,vector<int>(n, INT_MAX));
        // vector<vector<int>> previousSum (n,vector<int>(n, INT_MAX));
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }
        int score = turnScore(piles, left, right, turn, cache, prefixSum);        // total score at top of tree
                                                                       // total score = Alice score - Bob score
        return score;
    }
};

int main(){
    Solution sol;
    vector<int> piles1 = {5,3,4,5};
    vector<int> piles2 = {3,7,2,3};          
    vector<int> piles3 = {3,2,10,4};   
    vector<int> piles4 = {2,3,5,1};       
    cout<<sol.stoneGameVII(piles4)<<endl;
}
