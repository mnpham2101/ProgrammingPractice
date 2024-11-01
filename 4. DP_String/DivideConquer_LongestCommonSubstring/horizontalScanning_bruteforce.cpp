class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string ans = strs[0];
        for (int i=1; i< strs.size(); i++){
            commonPrefix(ans, strs[i]);
            if (ans.empty())
                return ans;
        }
        return ans;
    }

private:
    void commonPrefix(string& prefix, string& str) {
        for (int i=0; i <prefix.size(); i++){
            if (prefix[i] != str[i]){
                prefix = prefix.substr(0, i);
                return;      
            }
        }
    }
};