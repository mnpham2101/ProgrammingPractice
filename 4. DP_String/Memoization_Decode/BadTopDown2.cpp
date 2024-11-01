class Solution {
    int numberOfResult( string s, int startIndex, int length){
        // base
        if (startIndex >= s.length())
            return 0;
        cout<<"startIndex "<<startIndex<<" length "<<length<<" decode "<<s.substr(startIndex, length)<<endl;     
        
        if (s[startIndex] == '0')
            return 0;

        if (startIndex == s.length() || startIndex + length == s.length() && stoi(s.substr(startIndex, length)) <=26){                              // condition is not sufficient, case [123456789]
            cout<<" startIndex "<<startIndex<<" length "<<length<<" decode "<<s.substr(startIndex, length)<<" ans branch end: "<<1<<endl;
            return 1;
        }
        // memoization
        // recursive relation
        int ans = 0;
        if (length == 1){
            ans += numberOfResult(s, startIndex+length, 1);
            ans += numberOfResult(s, startIndex, 2);                 // issue 2: causing duplicate for example [1023] then the decoded should be: [10,2,3], [10,23] or ans=2
                                                                     // this code causes: [10,2,3], [10,2,23], [10,23]
        }
        if (length == 2){                                            // issue 1: if substr = "78", it does on to case length=1  ==> no stop on this branch ==> need condition to prevend deeper traverse
            ans += numberOfResult(s, startIndex+length, 1);
            ans += numberOfResult(s, startIndex+length, 2);          // issue 2: causing duplicate 
        }
                
        return ans;
    }
public:
    int numDecodings(string s) {
        int startIndex = 0;
        return numberOfResult(s, startIndex, 1);
    }
};


/*
The above code is good for [12] even [123]
        [12]
    [1]
[2]       [12]    ok, for length=1, index = 0, go to length=1, index 1, and length=2 index=0

The above code is not good for [1023]
                    [1023]
                [1]
            [0]      [10]    
                [2]         [23]
            [3]      [23]  

decode = [1,10,2,3],  [1,10,2,23], [10,10,23],   the case [1,10,2,23] is not valid. 
       
*/

