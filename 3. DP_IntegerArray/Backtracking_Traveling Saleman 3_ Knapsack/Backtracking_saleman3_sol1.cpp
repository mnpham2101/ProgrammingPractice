#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

// backtracking approach with small input size n<=30
int costLimit;
int numberOfCities;
int costOfcity[29];               // cost to visit the city
int valueOfCity[29];              // value earned from the city
// Step 1: mark candidates as visited or not visited
bool visited[29] = {false};
int res = 0;

void init(){
    cin >> costLimit>>numberOfCities;
    for(int city=1; city<=numberOfCities; city++){
        cin >> costOfcity[city] >> valueOfCity[city];
    }
}

// brute force approach with backtracking to eliminate counting the city that was already visited.
void Try(int startingCity, int value, int cost){

    // log
    cout << "startingCity "<<startingCity<<" cost "<<cost<<" value "<<value<<endl;
    // Step 3: Stop condition, return result
    if (cost > costLimit){
        return;
    }
    else{
        res = max(res,value);
        for(int city=1; city<=numberOfCities; city++){                                  // Step 2: consider all cities as potential candidate
            if (visited[city] == false && startingCity != city ){                       // Step 2.1: check condition for next candidate city to visit
                visited[city] = true;                                                   // Step 2.2: mark city as visited
                Try(city, value + valueOfCity[city], cost + costOfcity[city]);          // count this distance from starting city to next candidate city
                visited[city] = false;                                                  // Step 2.3: unmark city as unvisited so that after backtracking, we can put it back to candidate list
            }
        }
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