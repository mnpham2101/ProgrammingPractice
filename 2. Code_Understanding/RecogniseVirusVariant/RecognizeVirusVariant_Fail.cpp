#include <iostream>
#include <set>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer
set<int> virus;     // key = B[i] and key= variant of B[i]

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void OutputData(void)
{
	cout << sol;
}

void SetVariant(){
	for (int i = 0; i < M; i++) {
        virus.insert(B[i]);

	}
	int max = *(virus.rbegin());
	int min = *(virus.begin());
	// cout<<"max "<<max<<" min "<<min<<endl;

	// add each element of B[] to THE SAME possible values
	for (int i=1; i<= (100-max); i++){
		for (int j =0; j<M; j++ ){
			int variant = B[j]+i;
			// cout<<"variant "<<variant<<endl;
			virus.insert(B[j]+i);
		}
	}
	// subtract each element of B[] to THE SAME possible values
	for (int i=min; i>=0; i--){
		for (int j =0; j<M; j++ ){
			int variant = B[j]-i;
			// cout<<"variant "<<variant<<endl;
			virus.insert(variant);
		}
	}
}

int Find(int start)
{
	bool isVirus = false;
	for (int j= 0; j<M; j++ ){								// search the next M continuous element of A[] for virus.
		int value = A[start+j];
		if (virus.find(value) != virus.end()){				// if a byte element matches, set True, continue to the item in A[]
			isVirus = true;
		}
		else {
			isVirus =false;									// if any byte element not matched, return 0
			break;
		}
	}

	if (isVirus) return 1;
	else return 0;
}

void Solve(void)
{
	int i;

	for (i = 0; i <= N - M; i++) {
		sol += Find(i);
	}
}

int main(void)
{
	InputData(); // Input
	SetVariant();
	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}