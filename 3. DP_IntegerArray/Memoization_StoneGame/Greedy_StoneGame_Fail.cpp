#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Greedy solution
class Solution {
public:
    bool stoneGame(vector<int> &piles)
    {
        int aliceScore = 0;
        int bobScore = 0;
        int left = 0;
        int right = piles.size() - 1;
        sort(piles.begin(), piles.end());
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[left] > piles[right] && i % 2 == 0)
            {
                aliceScore += piles[left];
                left++;
            }
            else if (i % 2 == 0)
            {
                aliceScore += piles[right];
                right--;
            }
            else if (piles[left] > piles[right])
            {
                bobScore += piles[left];
                left++;
            }
            else
            {
                bobScore += piles[right];
                right--;
            }
        }
        return aliceScore > bobScore ? 1 : 0;
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
