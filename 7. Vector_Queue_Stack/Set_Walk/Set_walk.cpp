#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int N;
int T;
vector<int> P;                      //position of each person
vector<int> S;                      //spead of each person
vector<int> positionAfterT;         //position after T time
set<int> group;                     //group the people that would be at the same position after T time. No overpass is allowed.

int farthestPosition = INT_MAX;

// find a group of people that would arrive at the same time
void Input() {
	cin >> N >> T;
	P.resize(N);
	S.resize(N);
	positionAfterT.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		positionAfterT[i] = P[i] + S[i] * T;
	}

	for (int i = 0; i < N; i++) {
		cout<<positionAfterT[i] <<" ";
	}
	cout << endl;

}

void Solve() {
	group.insert(positionAfterT[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		if (positionAfterT[i] > positionAfterT[i + 1]) {
			group.insert(positionAfterT[i + 1]);
		}
		else
			group.insert(positionAfterT[i]);
	}
	cout << group.size();
}

int main() {
	Input();
	Solve();
}