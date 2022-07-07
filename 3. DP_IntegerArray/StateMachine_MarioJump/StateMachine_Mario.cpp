#include <iostream>
#include <algorithm>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int Solving() {
	int EvenState = P[0];
	int EvenHoldState = 0;
	int OddState  = 0;
	int OddHoldState=0;
	int maxResult = 0;
    for (int i = 1; i<N; i++){
			int previousEvenHoldState = EvenHoldState;
			int previousEvenState = EvenState;
			int previousOddState = OddState;
			int previousOddHoldState = OddHoldState;
			
			EvenHoldState = max(previousEvenState, previousEvenHoldState);
			OddHoldState = max(previousOddState, previousOddHoldState);
			EvenState = max(previousOddState +P[i] , previousOddHoldState+P[i] );
			OddState = max(previousEvenState-P[i], previousEvenHoldState-P[i]);
			
    } 
	return max(max(EvenState, OddState), max(EvenHoldState, OddHoldState));
}
				
int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
    
	ans = Solving();
	
	cout << ans << endl;	//	Output answer
	return 0;
}