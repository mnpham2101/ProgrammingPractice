#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool compare( vector<int> o1, vector<int>o2){
        if (o1[0] == o2[0]){
            if (o2[1] <o1[1]) return true;         //vector o1 is biger and covers vector o2  ==> back/right ==> ascending order
            else return 0;
        }
        else if (o1[0] < o2[0]) return true;
        else return false;
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        int end=0;
        int prev_end=0;
        sort(intervals.begin(), intervals.end(), compare );
        for (auto currentInterval : intervals) {
            end = currentInterval[1];
            if (prev_end <end) {
                result++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,4}, {2,8}, {3,6}};
    return 0;
}