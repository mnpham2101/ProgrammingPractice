#include<vector>
#include<set>
#include<iostream>
using namespace std;

/* create sliding windows with size from 1 to k, defined by left, right boundary
 * starting from 0, increase right boundary, check the condition abs(nums[left]-nums[right]) <= t and abs(left - right)<=k
 * shift slidingWindow to the left when abs(left - right) >= k
 * Bug with the left, right value
 * the set::upper_bound , lower_bound should be used as left, right index
 * the set already sort the values such so that we only the use value min, max value at the boundary  
 */
class Solution {
public:
    // Sliding windows
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // Step 1: create initial boundary for sliding window. minSize = 1, maxSize = k
        int left=0, right = left+1;
        set<long long> slidingWindow;                     // set is ascendingly ordered
        slidingWindow.insert((long long)nums[left]);
        for (int right = left+1; right< nums.size(); right++){
            cout<<"nums[]: "<<nums[left]<<" "<<nums[right]<<" index "<<left<<" "<<right<<endl;           
            /* abs(nums[right]-nums[left])<=t then: 
            *  nums[right]-nums[left]     <=  t     ==> nums[right] - t <= nums[left]; thus nums[left] is upperBound , if found in set => meet condition 
            *  or nums[right]-nums[left]  >= -t     ==> nums[right] + t >= nums[left]; thus nums[left] is lowerBound , if found in set => meet condition  
            */   
            long long diff  = (long long) nums[right] - (long long) t ;
            auto upperBound = slidingWindow.upper_bound(diff);
            long long sum   = (long long) nums[right] + (long long) t ;    
            auto lowerBound = slidingWindow.lower_bound(sum);
            
            if (upperBound != slidingWindow.end() ){
                cout<<"   condition upper-bound pass "<<endl;
                cout<<"      diff "<<diff<<" upper bound "<<*upperBound<<endl;
                if (right-left <=k){                                       // BUG 1: fail TC [1,5,9,1,5,9] k=2, t=3
                    cout<<"      condition2 pass "<<endl;
                    return true;
                }
            }
            
            else if (lowerBound != slidingWindow.end() ){
                cout<<"   condition lower-bound pass "<<endl;
                cout<<"      diff "<<diff<<" lower bound "<<*lowerBound<<endl;
                if ( left-right <=k){                                      // BUG 1: fail TC [1,5,9,1,5,9] k=2, t=3
                    cout<<"      condition2 pass "<<endl;               
                    return true;
                }
            }

            slidingWindow.insert((long long)nums[right]);
            // step 2: shift sliding windows                 
            if (abs(right -left) >= k){                                     // BUG 1: fail TC [1,5,9,1,5,9] k=2, t=3
                slidingWindow.erase(nums[left]);                        
                left++; 
                cout<<"   update left"<<left<<endl;
                slidingWindow.insert((long long)nums[left]);
            }
        }
        return false;
    }
};