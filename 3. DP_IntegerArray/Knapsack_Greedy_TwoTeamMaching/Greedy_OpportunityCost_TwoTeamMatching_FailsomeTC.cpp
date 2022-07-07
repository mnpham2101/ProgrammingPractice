#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

queue<int> resultList;

static bool sortByOpportunityCost (vector<int> FirstCandidate, vector<int>SecondCandidate) {
    if ((FirstCandidate[0] - FirstCandidate[1] ) < (SecondCandidate[0] - SecondCandidate[1]))
        return 1;   //sort by ascending order  ==> high = back
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
    // Bug check:
    // int s = candidateSet.size();     // s must be equal to n
    // cout <<s<<endl;
    // cout <<n<<endl;
    // step 2: make decision based on ascending order of candidateASkill and candidateBSkill(highest = back)
    sort(begin(candidateSet), end(candidateSet), sortByOpportunityCost);
    long long int testCaseResult =0;
    int numTeamA=0;
    int numTeamB=0;
    int teamA_candidate =0;
    int teamB_candidate =0;
    for (int i = n; i>0; i--){                    // pick the candidates with highest skill dif
        teamA_candidate = candidateSet[i-1][0];
        teamB_candidate = candidateSet[i-1][1];
        // choose candidate with more skills  as long as dif<K
        if (((teamA_candidate  - teamB_candidate)> 0) && abs(numTeamA-numTeamB)<=K){    
            testCaseResult += teamA_candidate;
            numTeamA++;
        }
        else if (((teamA_candidate  - teamB_candidate)< 0) && abs(numTeamA-numTeamB)<=K){
            testCaseResult += teamB_candidate;
            numTeamB++;
        }
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