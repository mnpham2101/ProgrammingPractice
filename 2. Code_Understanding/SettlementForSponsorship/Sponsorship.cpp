#include <iostream>
using namespace std;

int N;//Number of sponsored goods
int D[100000 + 10];//Preference
int sol = -30001;//Maximum preference of the first method

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> D[i];
	}
}

void Solve()
{
    // Deprecated code
    // int i, sum = 0;
	// for (i = 0; i < N - 2; i++) {
	// 	sum = D[i] + D[i + 1] + D[i + 2];
	// 	if (sum > sol) sol = sum;
	// }

    // Modified code
    int maxSum=D[0];
    int sum=D[0];
    for (int i = 1 ; i< N; i++){
        // sum = max(nums[i], sum+nums[i]);
        if (sum>0)                //same as if (nums[i]<sum[0]+nums[i])
            sum += D[i];
        else
            sum = D[i];
        if (sum>maxSum) {
            maxSum = sum;
        }
    }
    sol = maxSum;
}


int main(){
	InputData();//Input function
	Solve();
	cout << sol << endl;//Output
	return 0;
}