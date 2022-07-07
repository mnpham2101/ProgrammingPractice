#include <vector>
using namespace std;
/* You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's,
where 0 means empty and 1 means not empty, and an integer n,
return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if (flowerbed[0]==0 && flowerbed.size()==1)
            count++;
        else if (flowerbed[0]==0 && flowerbed[1]==0) {
            flowerbed[0]=1;
            count++;
        }

        for (int i=1; i<flowerbed.size()-1; i++){      // boundary = flowerbed.size()-1 for TC4, TC5
            if (flowerbed[i]==0 &&
                flowerbed[i-1] !=1 &&
                flowerbed[i+1] !=1)
            {
                flowerbed[i]=1;
                count++;
            }
        }

        if (flowerbed.size()>2 && flowerbed[flowerbed.size()-2]==0 && flowerbed[flowerbed.size()-1]==0 ){  //for TC4. TC5
            flowerbed[flowerbed.size()-1]=1;
            count++;
        }

        if (count >= n) return true;
        else return false;
    }
};

int main (){
    Solution sol;
    vector<int> flowerbed0 = {0,0,1,0,1}; int n0=1;
    vector<int> flowerbed1 = {1}; int n1=0;
    vector<int> flowerbed2 = {1,0,0}; int n2=1;
    vector<int> flowerbed3 = {0,0,0,0,0,1,0,0}; int n3=0;               //TC4
    vector<int> flowerbed4 = {0}; int n3=0;
    vector<int> flowerbed5 = {1}; int n3=1;
    sol.canPlaceFlowers(s);
}