class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int maxCost = 0;
        unordered_map<char, int> charMap;
        for (int i = 0; i < chars.size(); i++) {
            charMap[chars[i]] = vals[i];
        }
        // brute force search s, use double for loop to combine all characters in s 
        for (int i = 0; i < s.size(); i++) {
            int cost = 0;
            for (int j = i; j < s.size(); j++) {
                char c = s[j];
                cout<<"char:"<<c<<endl;
                if (charMap.find(c) != charMap.end()) {
                    cout<<" found c in val="<<charMap[c];
                    cost += charMap[c];
                } else {
                    cout<<" add value "<<c - 'a' + 1<<endl;
                    cost += c - 'a' + 1;
                }
                maxCost = max(cost, maxCost);
            }
        }
        return maxCost;
    }
};