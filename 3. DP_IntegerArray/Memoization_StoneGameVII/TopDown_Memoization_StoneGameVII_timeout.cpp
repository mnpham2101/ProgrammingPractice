#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Tree traversing + memoization
class Solution {
public:
    
    int turnScore (vector<int>&piles, int left, int right, int turn, vector<vector<int>>&cache, vector<vector<int>>&previousSum){
        // cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
        int sum = 0, a=0,b=0;
        // base case
        if (left>right) return 0;           // must have because if not, for case left=0, right=1, if(cache[left][right]) return segfault 
        // if (left== right)                // no neccessary since it is included in recursive case      
        // memoization - return via cache
        if (cache[left][right] !=INT_MAX ){
            // cout<<"return cache["<<left<<"]["<<right<<"]="<<cache[left][right]<<endl;
            return cache[left][right];
        }
        // starting, no one play yet.
        if (turn == 0){                                                             
            int sum = 0;
            int a = turnScore(piles, left, right-1, turn+1, cache, previousSum);
            int b = turnScore(piles, left+1, right, turn+1, cache, previousSum);            
            int c = max(a,b);
            // cout<<"sum:"<<sum<<" a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
            return c;
        }  
        
        // both players scores when left <= right 
        // input left, right indicates the range of remaining cards after the player removes a card
        // score = sum (left -> right) + turnResult (leftNext, rightNext, nextTurn)
        else if ((left <= right) && (turn %2 == 0)){                                 // Bob plays      
            if (previousSum[left][right]!=INT_MAX){
                sum = previousSum[left][right];
            }
            else{
                for (int i = left; i<=right; i++ ){             // this caused time out !!!
                    sum -= piles[i];                                                // score is different Alice - Bob
                    previousSum[left][right] = sum;
                }
            }
            
            a = turnScore(piles, left+1, right, turn+1, cache, previousSum);  
            b = turnScore(piles, left, right-1, turn+1, cache, previousSum);                                                       
            cache[left][right] = sum + max(a,b);                        // max(a,b) is the score of the next player, Alice 
            // cout<<"return value recursively"<<endl;
            // cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            // cout<<"sum:"<<sum<<endl;
            // cout <<"total "<< cache[left][right] <<endl;
            return cache[left][right];
        } 
        else if ((left <= right) && (turn %2 != 0)){                                 // Alice plays
            if (previousSum[left][right]!=INT_MAX){
                sum = previousSum[left][right];
            }
            else{
                for (int i = left; i<=right; i++ ){
                    sum += piles[i];                            // score is different Alice - Bob
                    previousSum[left][right] = sum;
                }
            }
            a = turnScore(piles, left+1, right, turn+1, cache, previousSum);  
            b = turnScore(piles, left, right-1, turn+1, cache, previousSum);                                                   
            cache[left][right] = sum + min(a,b);                                // min(a,b) is the score of the next player, Bob  
            // cout<<"return value recursively"<<endl;
            // cout<<"turn: "<<turn<<" (left,right="<<left<<","<<right<<")"<<endl;
            // cout<<"sum:"<<sum<<endl;
            // cout <<"total "<< cache[left][right] <<endl;
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
        vector<vector<int>> previousSum (n,vector<int>(n, INT_MAX));
        int score = turnScore(piles, left, right, turn, cache, previousSum);        // total score at top of tree
                                                                       // total score = Alice score - Bob score
        return score;
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
