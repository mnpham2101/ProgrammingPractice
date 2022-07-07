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
    int value=0;
	int suitableMax=0;
	int suitableMin=0;
    for (int jump=0; jump <N; jump++){
        if ((jump % 2) == 0){
			for (int i=0; i<N;i++){
				// find a suitableMax value				
			}
			value += suitableMax;
        }
        else {
				// find a suitableMin value				
            value -= min;
        }
    }
}


int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
    
	ans = Solving();
	
	cout << ans << endl;	//	Output answer
	return 0;
}
