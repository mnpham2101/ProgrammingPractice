class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // vector<bool> seen(26, false);
        bool seen[26] = { [0 ... 25] = false} ;         // must use designated initializer
        for (char c: letters)
            seen[c - 'a'] = true;
        while (true) {                           
            target++;   
            if (target > 'z') 
                target = 'a';                   // letters 'wrap' around
            if (seen[target - 'a']== true) {
                
                return target;
            }        
        }
    }
};