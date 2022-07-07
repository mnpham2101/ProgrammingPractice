#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

queue<int> resultList;

static bool sortByOpportunityCost (vector<int> FirstCandidate, vector<int>SecondCandidate) {
    if ((FirstCandidate[1] - FirstCandidate[0] ) > (SecondCandidate[1] - SecondCandidate[0]))
        return 1;   //sort by descending order of b-a ==> high = front, i=0
        else return 0;
};

void input(vector<int> & teamA, vector<int> & teamB, int &n, int &K){
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
}

void runLogic(vector<int> & teamA, vector<int> &teamB, queue<int>&resultList, int n, int K){
    // step 1: make candidate list  based on skil, ascending order  (highest = back)
    vector <vector<int>> candidateSet(n);
    for (int i=0; i<n; i++){
        int candidateASkill = teamA.back();
        int candidateBSkill = teamB.back();
        candidateSet[i].push_back(candidateASkill);
        candidateSet[i].push_back(candidateBSkill);
        teamA.pop_back();
        teamB.pop_back();
    }
    // step 2: make decision based on descending order of (candidateBSkill - candidateASkill) (highest = front)
    sort(begin(candidateSet), end(candidateSet), sortByOpportunityCost);
    long long int testCaseResult =0;
    int teamA_candidate =0;
    int teamB_candidate =0;
    int m = n-K;
    if (m & 1){                     // what is this logic for ??????? 
        ++m, --K;                   // what is this logic for ??????? 
    }
    m /= 2;
    // step 2.1: For higher value of (B-A), pick candidate B
    for (int i = 0; i < m; ++i){
        teamB_candidate =candidateSet[i][1];                        // m is lower bound of team B: team B can have from m to m+K
        testCaseResult += teamB_candidate;
    }
        
    for (int i = m; i < m + K; ++i){
        teamB_candidate =candidateSet[i][1];
        teamA_candidate =candidateSet[i][0];
        testCaseResult += max(teamB_candidate, teamA_candidate);      // for members in K range, we picked the candidate with higher skill sets from teamA and teamB
    }
    // step 2.3: For lower value of (B-A), pick candidate A      
    for (int i = m + K; i < n; ++i){
        teamA_candidate =candidateSet[i][0];                         // m+K is higher bound of team A: team A can have from m to m+K. In term of indexing, i=m+k is lower boundary.
        testCaseResult += teamA_candidate;
    }
        
    resultList.push(testCaseResult);
}

void output(queue<int>&resultList){
    while (resultList.size() !=0){
        int testCaseResult = resultList.front();                    // first in first out
        cout<<testCaseResult<<endl;
        resultList.pop();
    }
}

void runTestCase(){
    vector<int> teamA;
    vector<int> teamB;
    int n=0;        // number of team member
    int K=0;        // number of differences between team
    input(teamA, teamB, n, K);
    runLogic(teamA, teamB,resultList, n, K);
}

int main(){
    int T;
    cin>>T;
    for (int i=1; i<=T; i++){
        runTestCase();
    }
    output(resultList);
}