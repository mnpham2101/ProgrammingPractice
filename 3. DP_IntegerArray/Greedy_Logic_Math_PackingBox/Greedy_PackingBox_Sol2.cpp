#include <iostream>
using namespace std;

int N;//The number of goods to send
int C[10];//The number of available bills (in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10] = { 0,0,0,0,0,0,0,0,0,0 };//The number of bills to use
int BoxSize[10] = { 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 };
int totalBox = 0;

void InputData() {
	int i;
	cin >> N;
	for (i = 0; i < 10; i++) {
		cin >> C[i];
	}
}

void OutputData(int ans) {
	int i;
	cout << ans << endl;
	for (i = 0; i < 10; i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}


void Solve() {
	// get max sol[i] until total += sol[i]*BoxSize[i] > N
	int totalValue = 0;
	int i_max = 0;
	int biggestBoxSize;				// the biggest box size is the one to be filled up by adjusting number of smaller box
	int remain = 0;
	// Step 1: fill up the BoxSize[i] with max number in C[i] until total >= N
	for (int i = 0; i < 10; i++) {
		sol[i] = C[i];
		totalBox += sol[i];
		totalValue += sol[i] * BoxSize[i];
		if (totalValue > N) {
			i_max = i;
			remain = totalValue - N;
			break;
		}
		if (totalValue == N) {
			return;
		}
	}


	// Step 2: decrease the number of smaller box size until remainder == 0
	for (int i = i_max; i >= 0; i--) {              // start from the next smaller box size to the smallest
		int numberOfBoxToReduce = remain / BoxSize[i];
		sol[i] -= numberOfBoxToReduce;                   // reduce the number of box for smaller box size
		totalBox -= numberOfBoxToReduce;
		remain = remain % BoxSize[i];                // calculate remain for next iteration - smaller box size
		if (remain == 0) {
			return;
		}
	}
}

int main() {


	InputData();//	Input function

	//	Create the code
	Solve();


	OutputData(totalBox);//	Output function

	return 0;
}