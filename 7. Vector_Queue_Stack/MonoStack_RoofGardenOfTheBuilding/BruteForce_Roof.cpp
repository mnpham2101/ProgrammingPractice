#include <iostream>
#include <vector>
using namespace std;

int N;//Number of buildings
int H[80010];//Height of buildings[80000];
int answer = 0;
void Input_Data(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
}

void Output_Data(int ans) {
    cout << answer;
}

void Solve() {
    for (int westBuilding = 0; westBuilding < N; westBuilding++) {
        for (int eastBuilding = westBuilding + 1; eastBuilding < N; eastBuilding++) {
            if (H[eastBuilding] >= H[westBuilding]) {
                break;
            }
            if (H[eastBuilding] < H[westBuilding]) {
                answer++;
            }
        }
    }
}

int main() {
    Input_Data();//  Input function

    //  Create the code
    Solve();

    Output_Data(answer);//  Output function

    return 0;
}