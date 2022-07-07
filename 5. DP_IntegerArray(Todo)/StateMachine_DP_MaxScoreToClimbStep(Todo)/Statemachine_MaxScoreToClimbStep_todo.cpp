#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int N;								// number of steps
vector<int>P;						// score of the steps
int answer = 0;

void Input() {
	cin >> N;
	P.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
	cout << endl;
}

void Solve() {
	int oneStep = P[0];
	int oneStepThenHold = 0;
	int twoStep = P[1];
	int twoStepThenHold = 0;
	int maxResult = 0;
	for (int i = 2; i < N; i++) {
		cout << oneStep << " "  << twoStep << " " << oneStepThenHold << " " << twoStepThenHold << endl;
		int previousOneStep = oneStep;
		int previousTwoStep = twoStep;
		int previousOneStepThenHold = oneStepThenHold;
		int previousTwoStepThenHold = twoStepThenHold;

		oneStepThenHold = max(previousOneStep, previousOneStepThenHold);
		twoStepThenHold = max(previousTwoStep, previousTwoStepThenHold);
		oneStep = max(previousOneStep + P[i], previousTwoStepThenHold + P[i]);

		twoStep = max(previousOneStep + P[i], previousOneStepThenHold + P[i]), previousTwoStep + P[i]);

	}
	cout << max(oneStep, twoStep) << endl;;
	cout << max(oneStepThenHold, twoStepThenHold) << endl;

	answer = max(max(oneStep, twoStep), max(oneStepThenHold, twoStepThenHold));

	cout << answer;
}

int main() {
	Input();
	Solve();
}