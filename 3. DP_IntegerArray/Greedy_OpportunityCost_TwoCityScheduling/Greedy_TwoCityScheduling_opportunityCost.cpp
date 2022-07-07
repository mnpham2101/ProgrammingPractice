#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
    static  {
        if ((1stChoice[0] - 1stChoice[1] ) > (2ndChoice[0] - 2ndChoice[1])) return 1;
        else return 0;

    };
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort(begin(costs), end(costs), sortByOpportunityCost);

        int total = 0;
        int n = costs.size() / 2;

        for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
        return total;
    };
};