#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        // faceA for counting the occurence in tops
		// faceB for counting occurence of numbers in bottoms
        // same for counting when both tops and bottoms have same occurences
        vector<int> faceA(7), faceB(7), same(7);

        for(int i = 0; i < n; ++i)
        {
            ++faceA[tops[i]];
            ++faceB[bottoms[i]];

            if(tops[i] == bottoms[i])
                ++same[tops[i]];
        }

        int minRotation = INT_MAX;

		// all possibilities from 1 to 6
        for(int i = 1; i<=6; ++i)
        {
            if(faceA[i] + faceB[i] - same[i] == n)
                minRotation = min(minRotation , min(faceA[i],faceB[i]) - same[i]);
        }

        return minRotation == INT_MAX ? -1 : minRotation;

    }
};

int main(){
    Solution sol;

    vector<int> top1 = {1,2,1,1,2,2};
    vector<int> bottom1 = {2,1,2,2,2,2};

    vector<int> top2 = {1,1,1};
    vector<int> bottom2 = {2,2,2};

    vector<int> top3 = {2,1,2,4,2,2};
    vector<int> bottom3 = {5,2,6,2,3,2};

    vector<int> top4 = {3,5,1,2,3};
    vector<int> bottom4 = {3,6,3,3,4};

    sol.minDominoRotations(top1, bottom1);
}