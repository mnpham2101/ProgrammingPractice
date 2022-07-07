#include <iostream>
#include <algorithm>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer

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

int Find(int start)
{
	int i;

    int dataUnderAnalysis [M];
    std::copy(A+start, A+(start+M), dataUnderAnalysis);                 // since variant could be reordered from original virus
                                                                        // we compare data vs variant in sorted order
    sort(B, B+M);                                                       // if variant is addition/subtraction of original virus
    sort(dataUnderAnalysis, dataUnderAnalysis+M);                       // every item in (data -B) is the same as "change"
    int change = dataUnderAnalysis[0] - B[0];
	for (i = 0; i < M; i++) {
		if ((B[i] != dataUnderAnalysis[i]) && 
            (dataUnderAnalysis[i] - B[i]) != change) return 0;
	}
	return 1;
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

	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
