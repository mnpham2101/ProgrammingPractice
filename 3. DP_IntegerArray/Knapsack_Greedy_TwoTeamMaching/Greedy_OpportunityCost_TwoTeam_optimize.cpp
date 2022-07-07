#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

static bool sortByOpportunityCost (vector<int> FirstCandidate, vector<int>SecondCandidate) {
    if ((FirstCandidate[1] - FirstCandidate[0] ) > (SecondCandidate[1] - SecondCandidate[0]))
        return 1;   //sort by descending order of b-a ==> high = front, i=0
        else return 0;
};

long long int runLogic(vector<int> & teamA, vector<int> &teamB, int n, int K){
    // step 1: make candidate list  based on skil, ascending order  (highest = back)
    vector <vector<int>> candidateSet(n);
    for (int i=0; i<n; i++){
        candidateSet[i].push_back(teamA[i]);
        candidateSet[i].push_back(teamB[i]);
    }
    // teamA.clear();
    // teamB.clear();
    // step 2: make decision based on descending order of (candidateBSkill - candidateASkill) (highest = back)
    sort(begin(candidateSet), end(candidateSet), sortByOpportunityCost);
    long long int testCaseResult =0;
    int m = n-K;        
    if (m & 1){         // what does it mean ?????????????????????? 
        ++m, --K;
    }
    m /= 2;
    // step 2.1: For higher value of (B-A), pick candidate B
    for (int i = 0; i < m; ++i){
                               // m is lower bound of team B: team B can have from m to m+K
        testCaseResult += candidateSet[i][1];
    }
        
    for (int i = m; i < m + K; ++i){
        
        testCaseResult += max(candidateSet[i][0], candidateSet[i][1]);      // for members in K range, we picked the candidate with higher skill sets from teamA and teamB
    }
    // step 2.3: For lower value of (B-A), pick candidate A      
    for (int i = m + K; i < n; ++i){
                                // m+K is higher bound of team A: team A can have from m to m+K. In term of indexing, i=m+k is lower boundary.
        testCaseResult += candidateSet[i][0];
    }
    return testCaseResult;     
}

int main(){
    int T;
    cin>>T;
    for (int i=1; i<=T; i++){
        vector<int> teamA;
        vector<int> teamB;
        int n=0;        // number of team member
        int K=0;        // number of differences between team
        cin>>n;
        cin>>K;
        int skills;
        for (int i = 1; i<=n; i++){
            cin>>skills;
            teamA.push_back(skills);
        }

        for (int i = 1; i<=n; i++){
            cin>>skills;
            teamB.push_back(skills);
        }
        cout<<runLogic(teamA, teamB, n, K)<<endl;
    }
}