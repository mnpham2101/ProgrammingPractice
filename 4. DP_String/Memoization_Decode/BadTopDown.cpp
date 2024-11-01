class Solution {
    int numberOfResult( string s, int startIndex, int length){
        cout<<"startIndex "<<startIndex<<" length "<<length<<" decode "<<s.substr(startIndex, length)<<endl;     
        // base
        if (startIndex == s.length() || startIndex + length == s.length() ){
            cout<<" startIndex "<<startIndex<<" length "<<length<<" decode "<<s.substr(startIndex, length)<<" ans branch end: "<<1<<endl;
            return 1;
        }
               
        // memoization
        // recursive relation
        int ans = 0;
        if ( stoi(s.substr(startIndex, length)) <= 26){
            if (startIndex + length > s.length())
                return 0;
            ans += numberOfResult(s, startIndex+length, 1);
            cout<<" ans left "<<ans<<endl;
            ans += numberOfResult(s, startIndex, 2);                        // this cause inf loop. Ex: [226]
            cout<<" ans right "<<ans<<endl;
        }
        return ans;
    }
public:
    int numDecodings(string s) {
        int startIndex = 0;
        return numberOfResult(s, startIndex, 1);
    }
};