#include <map>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        map<int,int> truster, trustee;
        for(auto t: trust)
        {
            int firstPerson = t[0];
            int secondPerson = t[1];
            truster[firstPerson]++;             // count the people that the first person trust
            trustee[secondPerson]++;            // count the people that trust second person
        }
        for(auto person: trustee){
            if (person.second == n-1  &&                         // the number of people that trust this person is everyone
                truster.find(person.first) == truster.end()){     // the person doesn't trust anyone
                return person.first;
            }
        }
        return -1;
    }
};