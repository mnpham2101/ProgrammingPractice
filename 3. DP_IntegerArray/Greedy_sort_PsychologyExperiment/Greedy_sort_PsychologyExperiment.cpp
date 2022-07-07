#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> answer;
int N;                                                          // map size 2<N<100
vector<int> A;

void InputData() {
    cin >> N;                                                   // number of candidates

    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

// use Greedy - Sort
void Solve() {
    sort(A.begin(), A.end());                                   // sort ascending order
    int left = 0;
    int right = N - 1;
    int best = abs(A[left] + A[right]);
    answer.first = left;
    answer.second = right;
    while (left < right) {
        if (abs(A[left] + A[right]) < best) {
            answer.first = left;
            answer.second = right;
            best = abs(A[left] + A[right]);
        }
        if (A[left] + A[right] < 0)                             // if sum<0, make it less negative
            left++;
        else if (A[left] + A[right] > 0)                        // if sum>0, make it less positive
            right--;
        else break;
    }
}

void OutputData() {
    cout << answer.first << " " << answer.second << endl;
}

int main() {
    InputData();//	Input function
    //	Create the code
    Solve();
    OutputData();
    return 0;
}