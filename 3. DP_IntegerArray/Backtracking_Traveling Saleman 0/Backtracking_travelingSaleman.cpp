#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[16][16];
// Step 1: mark candidates as visited or not visited
bool visited[16] = {false};
int res = INT_MAX;

void init(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
}


bool checkz(){
    for(int city=1;city<=n;city++){
        if (visited[city] == false){
            return false;
        }
    }
    return true;
}

// brute force approach with backtracking to eliminate counting the city that was already visited.
void Try(int startingCity,int cnt){
    if (cnt < res){
        // Step 3: Stop condition, return result
        if (checkz()){                                                      // stop when all city have been visited
            res = min(res,cnt + a[1][startingCity]);                        // a[1][startingCity]: cost to return to city 1. as required in problem description
        }
        else{
            for(int city=1;city<=n;city++){                                 // Step 2: consider all cities as potential candidate
                if (visited[city] == false && startingCity != city ){       // Step 2.1: check condition for next candidate city to visit
                    visited[city] = true;                                   // Step 2.2: mark city as visited
                    Try(city,cnt+a[startingCity][city]);                    // count this distance from starting city to next candidate city
                    visited[city] = false;                                  // Step 2.3: unmark city as unvisited so that after backtracking, we can put it back to candidate list
                }
            }
        }
    }
}


void process(){
    visited[1] = true;
    Try(1,0);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    init();
    process();

    return 0;
}