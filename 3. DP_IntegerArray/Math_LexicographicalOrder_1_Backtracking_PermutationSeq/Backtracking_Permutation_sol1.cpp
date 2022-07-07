#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<vector<int>> permutationList;                    // a list of permutation configs
    vector<int>permutation;                                 // a single permutation config
    unordered_map<int,bool>markCandidates;                  // indicates if the candidate is used for permutation already (true) or not (false)

    // recursive backtracking algorithm
    void backtracking(vector<int>& nums, int index){

        // base case
        if (index > nums.size()-1){  // reaching the lowest level of permutation tree
            // acquire a single permutation configuration, push_back to list
            permutationList.push_back(permutation);
            return;                       // return permutation for that starts with candidates at firstIndex
        }

        // recursive cases
        for (int candidate : nums ){                        // for loop adds next candidates to permutation at the level indicated by index
            if (markCandidates[candidate] != true){         // if candidate has not been used in permutation config
                markCandidates[candidate]= true;            // set true: the candidate is now used for permutation config
                permutation[index]=candidate;               // add the candidate to the position indicate by index
                backtracking(nums, index+1);                // goes to deeper level by index+1
                // restore condition:
                // after backtracking returning result, we go back to higher level, previous index
                // we need to remark the candidate from lower level as false because, we want to put them back to candidate list for permutation
                markCandidates[candidate]= false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        // depth of tree created by permutation of N! is N (size of nums)
        // the number of child branches is N! => this is also the total size of permutationList
        // since there is not fast way to calculate N!, we don't resize permutationList

        // for each permutation config: the size is N
        permutation.resize(nums.size());

        // Step 1: premark all possible candidates as false => also have not been used in the permutation
        for (int i : nums){
            markCandidates[i]= false;
        }

        // Step 2: perform backtracking
        backtracking(nums, 0);               // backtracking starts with first tree level = 1

        return permutationList;
    }
};
