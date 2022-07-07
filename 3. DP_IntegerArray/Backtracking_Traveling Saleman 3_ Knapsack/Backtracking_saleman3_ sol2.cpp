#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

// backtracking approach with small input size n<=30
int costLimit;
int numberOfCities;
int costOfcity[2001];               // cost to visit the city
int valueOfCity[2001];              // value earned from the city
// Step 1: mark candidates as visited or not visited
bool visited[2001] = {false};
int res = 0;
int remainValue[2001];
void init(){

    cin >> costLimit>>numberOfCities;
    for(int city=1; city<=numberOfCities; city++){
        cin >> costOfcity[city] >> valueOfCity[city];
    }
    for (int city = numberOfCities; city>=1; city--){
        remainValue[city] = valueOfCity[city+1] + valueOfCity[city];
    }
}

// brute force approach with backtracking to eliminate counting the city that was already visited.
void Try(int startingCity, int value, int cost){

    // log
    // cout << "startingCity "<<startingCity<<" cost "<<cost<<" value "<<value<<" remainValue "<<remainValue[startingCity]<<" maxValue "<<res<<endl;
    // Step 2:
    if (remainValue[startingCity]<res){
        // cout<<"stop at branch "<<endl;
        return;
    }
    // Step 4: Stop condition, return result
    if (cost > costLimit){
    	// cout<<"stop condition"<<endl;
        return;
    }
    else{
        res = max(res,value);
        for(int i=0; i<=1; i++)
        {
            if (i == 0)
            {
                                visited[startingCity] = false;                                                  // Step 2.3: unmark city as unvisited so that after backtracking, we can put it back to candidate list

                Try(startingCity+1, value, cost);
            }else{
                                visited[startingCity] = true;                                                   // Step 2.2: mark city as visited

                Try(startingCity+1, value + valueOfCity[startingCity], cost + costOfcity[startingCity]);          // count this distance from starting city to next candidate city
            }
        }

                                          // Step 2: consider all cities as potential candidate
                                 // Step 2.1: check condition for next candidate city to visit
                visited[startingCity] = true;                                                   // Step 2.2: mark city as visited
                Try(startingCity+1, value + valueOfCity[startingCity], cost + costOfcity[startingCity]);          // count this distance from starting city to next candidate city
                visited[startingCity] = false;                                                  // Step 2.3: unmark city as unvisited so that after backtracking, we can put it back to candidate list
                Try(startingCity+1, value, cost);

    }
}

void process(){
    visited[0] = true;
    Try(0,0,0);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    init();
    process();

    return 0;
}