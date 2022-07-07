#include <vector>
#include <iostream>
using namespace std; 


// DP equation - Greedy - Fail approach
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int right = piles.size()-1;
        int left = 0;
        bool AliceTurn = true; 
        int score[piles.size()];          // score is + if Alice score; score is - if Alice doesn't score
        memset(score, 0, sizeof(score));
        int previousScore = 0;
        for (int turn = 0; turn < piles.size(); turn++){
            // while (left<=right){
                if (AliceTurn){
                    // score[turn] = previousScore + max(piles[left], piles[right]);
                    if (piles[left]>= piles[right]){
                        score[turn] = previousScore + piles[left];                  // update DP equation O(n)
                        left++;
                    }
                    else{
                        score[turn] = previousScore + piles[right];
                        right--;
                    }
                    previousScore = score[turn];
                    AliceTurn = false;
                }
                else if (!AliceTurn){
                    // score[turn] = previousScore + min(-piles[left], -piles[right]);           // min because opponent wants to win ==> more negative score
                    if (piles[left]>= piles[right]){
                        score[turn] = previousScore - piles[left];
                        left++;
                    }
                    else{
                        score[turn] = previousScore - piles[right];
                        right--;
                    }
                    previousScore = score[turn];
                    AliceTurn = true;
                }
            // } 
        }
        if (score[piles.size()-1] > 0) 
            return true;
        else 
            return false;
    }
};

int main(){
    Solution sol;
    // vector<int> piles = {5,3,4,5};
    vector<int> piles = {3,7,2,3};              // Alice can choose either `3` on the left or right
                                                // choosing `3` on the right will lead to winning
                                                // the "DP Equation" however only make left choice.
                                                // this approach is also similar to a bad Greedy choice.
    cout<<sol.stoneGame(piles)<<endl;
}