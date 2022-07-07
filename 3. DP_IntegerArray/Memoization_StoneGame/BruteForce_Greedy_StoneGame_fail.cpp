#include <vector>
#include <iostream>
using namespace std;

// Brute Force + Greedy solution
class Solution {
public:
    
    int turnResult(vector<int>&piles, bool AliceTurn, int score, int left, int right){
        if (left> right){
            return score;
        }
        // player assumes to get the higher score whenever possible
        // it is a local optimum result, but not neccessary the ultimate good solution.
        else if ( (AliceTurn) && (piles[left] == piles[right]) )
        {
            score = score;
            cout<< score<< endl;
            return max( turnResult(piles, !AliceTurn , score + piles[left], left+1, right), 
                       turnResult(piles, !AliceTurn , score + piles[right], left, right-1));
        }
        else if ( (AliceTurn) && (piles[left] > piles[right]) )
        {
            score = score;
            cout<< score<< endl;
            return turnResult(piles, !AliceTurn , score + piles[left], left+1, right); 
        }
        else if ( (AliceTurn) && (piles[left] < piles[right]) )
        {
            score = score;
            cout<< score<< endl;
            return turnResult(piles, !AliceTurn , score + piles[right], left, right-1);
            
        }
        else if ((!AliceTurn) && (piles[left] == piles[right]))  
        {
            score = score;
            cout<< score<< endl;
            AliceTurn = true;
            return min( turnResult(piles, AliceTurn , score - piles[left], left+1, right), 
                       turnResult(piles, AliceTurn , score - piles[right], left, right-1));
        }
        else if ((!AliceTurn) && (piles[left] > piles[right])) 
        {
            score =score;
            cout<< score<< endl;
            AliceTurn = true;
            return turnResult(piles, AliceTurn , score - piles[left], left+1, right);
        }
        else if ((!AliceTurn) && (piles[left] < piles[right])) 
        {
            score =score;
            cout<< score<< endl;
            AliceTurn = true;
            return turnResult(piles, AliceTurn , score - piles[right], left, right-1);
        }
        else
            return false;    
    }
    
    bool stoneGame(vector<int>& piles) {
        int right = piles.size()-1;
        int left = 0;
        bool AliceTurn = true; 
        int score = 0;          // score is + if Alice score; score is - if Alice doesn't score
        score = turnResult(piles, AliceTurn, score, left, right );
        cout<< score << endl;               // in score để debug
        if (score<0) return false;
        else return true; 
    }
};

int main(){
    Solution sol;
    // vector<int> piles = {5,3,4,5};
    vector<int> piles = {3,7,2,3};          // TC pass
    vector<int> piles = {3,2,10,4};         // TC fails ==> if Alice picks the lower value 3 instead of 4
                                            // ==> Alice will win. 
    cout<<sol.stoneGame(piles)<<endl;
}
