#include <iostream>
using namespace std;

int N;//The number of goods to send
int C[10];//The number of available bills (in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10] = {0,0,0,0,0,0,0,0,0,0};//The number of bills to use
int BoxSize[10]={1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int totalBox = 0;

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}

void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}


// This solution fill up the box with C[i] uptil total > N, then compensate - empty the largest box.
// Adjust the number of smaller box so that the remainder could fill up the largest box.
//	WRONG: THIS IMPLEMENTATION ASSUME THE NUMBER OF THE LARGEST BOXSIZE IS 1 FOR ANSWER. This is not the case
void Solve(){
	// get max sol[i] until total += sol[i]*BoxSize[i] > N
	int totalValue=0;
	int i_max=0;
	int biggestBoxSize;				// the biggest box size is the one to be filled up by adjusting number of smaller box
	int remain=0;
	// Step 1: fill up the BoxSize[i] with max number in C[i] until total <= N
	for (int i = 0; i<10; i++){
		sol[i] = C[i];
		totalBox += sol[i];
		totalValue += sol[i]*BoxSize[i];
		if (totalValue > N) {
			biggestBoxSize = BoxSize[i];			// set the biggestBoxSize
			// compensating step, go back to the last box size
			i_max = i-1;
			totalValue -= sol[i]*BoxSize[i];
			totalBox -=sol[i];                   //	WRONG: THIS IMPLEMENTATION ASSUME THE NUMBER OF
												 // THE LARGEST BOXSIZE AS 1
			sol[i] = 0;
			break;
		}
		if (totalValue == N){
		    return;
		}
	}
	// Step 2: gradually decrease the number of smaller box size until remainder fit a bigger box
	for (int i=i_max; i>=0; i-- ){              // start from the next smaller box size to the smallest
		for (int j=sol[i]; j>=0; j--){			// decrease the number of smaller box size
			totalValue -= BoxSize[i];
			remain = N - totalValue;
			sol[i]--;
			totalBox --;
			if (remain == biggestBoxSize){
				sol[i_max+1]++;					// fill up the biggest box size and return answer
				totalBox += sol[i_max];			//	WRONG: THIS IMPLEMENTATION ASSUME THE NUMBER OF
												//THE LARGEST BOXSIZE AS 1
				return;
			}
			if (remain > biggestBoxSize){
				sol[i]++;
				totalValue += BoxSize[i];
				break;
			}
		}
	}
	for (int i = 0; i<10; i++){								// un-neccessary, could have calculated ans in earlier loop
		totalBox += sol[i];
	}
}

int main(){


	InputData();//	Input function

	//	Create the code
	Solve();


	OutputData(ans);//	Output function

	return 0;
}