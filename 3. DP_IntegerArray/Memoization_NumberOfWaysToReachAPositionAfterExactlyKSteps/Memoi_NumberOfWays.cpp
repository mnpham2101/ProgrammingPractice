#include<vector>
#include<iostream>
using namespace std; 

class Solution {
    vector<vector<int>> cache;
public:
    int topDown(int startPos, int endPos, int turn, int turnLimit){
        // cout<<"startPos "<<startPos<<" turn "<<turn<<endl;
        if (cache[startPos][turn] != -1)
            return cache[startPos][turn];
        if (turn > turnLimit){
            return 0;
        }
        else if ((startPos == endPos) &&
                 (turn == turnLimit)) {
            // cout<<" return 1 "<<endl;
            return 1; 
        }    
        else{
            cache[startPos][turn] = (topDown(startPos+1, endPos, turn+1, turnLimit) + 
                topDown(startPos-1, endPos, turn+1, turnLimit)) % 1000000007;
            return cache[startPos][turn];
        }
        return 0;    
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int result = 0;
        
        // just shifting start and end positions by same quantity
        // max value of k can be 1000 so if we have startpos as 0 then (startpos-k) would have been negative so shifting startPos and endPos save us from these cases 
        startPos+=1200;
        endPos+=1200;
        
        cache.resize(4000,vector <int> (k+2,-1));
        
        result +=topDown(startPos, endPos, 0, k);
        return result;
    }
};