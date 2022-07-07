#include <vector>
/*Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i,
and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.
*/
class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
        int result=0;
        sort(cookieSize.begin(), cookieSize.end() );          // sort ascending order (back = higher value)
        sort(greed.begin(), greed.end());                     // sort ascending order
        // assign large cookies to child that has more greed first  - remove the child after finding an suitable cookie size
        for (int i=0; i< cookieSize.size(); i++){
            if (greed.size() == 0) {
                break;
            }
            for (int j=0; j<greed.size(); j++){
                if (cookieSize.size()>0){
                    if (cookieSize[i] >= greed[j]) {
                        result++;
                        // cookieSize.erase(cookieSize.begin())     // removing the cookie at the front may remove non-suitable size
                        cookieSize.erase(cookieSize.begin() + i);   // removing the cookie whose size satisfies the greed//
                        greed.erase(greed.begin());
                        i--;                                        // track counting, otherwise, the outerloop breaks
                        j--;                                        // track counting, otherwise, the outerloop breaks
                        break;
                    }
                }
                else break;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int>greed = {5,6,7};
    vector<int>cookieSize = {1,2,3,5,8};
    sol.findContentChildren(greed,cookieSize);
}