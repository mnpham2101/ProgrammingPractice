#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int rightMost=0;
        int leftMost=0;
        vector<int> partition;
        unordered_set<char> repeatedCharacter;
        for (int left = 0; left< s.length(); left++){
            // fight the rightmost anchor for a partition
            for (int right = s.length()-1; right > left; right--){
                if (repeatedCharacter.find(s[left]) != repeatedCharacter.end()){
                    break;
                }
                if (s[right] == s[left]) {
                    repeatedCharacter.insert(s[right]);
                    rightMost = max(rightMost,right);
                    break;
                }
            }
            // when a partition a found
            if (left == rightMost){
                // and partition to result
                partition.push_back(rightMost - leftMost + 1);
                // start net partition
                leftMost = left+1;
                rightMost++;
            }
        }
        // if ((s.length()-1) - rightMost !=0){
        //     partition.push_back(s.length()-1 - leftMost + 1);
        // }
        return partition;
    }
};

int main(){
    Solution sol;
    string s1 = "eaaaabaaec";
    string s2 = "vhaagbqkaq";
    string s3 = "vaaq";
    string s4 = "ababcbacadefegdehijhklij";
    sol.partitionLabels(s1);
    return 0;
}