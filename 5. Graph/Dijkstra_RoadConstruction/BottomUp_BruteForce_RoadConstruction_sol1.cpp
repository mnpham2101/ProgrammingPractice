#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int answer = 0;
int N;               // map size 2<N<100
vector<vector<int>> landPrice;

void InputData() {
    cin >> N;
    string input;

    // vector<vector<int>> landPrice(N, vector<int>(N));
    landPrice.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            landPrice[i][j] = input[j] - '0';
        }
    }

    // Log: check input
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << landPrice[i][j] << " ";
        }
        cout << endl;
    }*/
}

// use recursive call to traver all branches of decision tree and returns values 2/10 TC pass
int recursive(int coordinateX, int coordinateY) {
    cout << "coordinateX " << coordinateX << " coordinateY " << coordinateY << endl;
    // base case:
    if (coordinateX == N - 1 && coordinateY == N - 1) {
        cout << "destination 0" << endl;
        return 0;
    }
    // recursive cases: Note: the order of those conditions is paramount. Need to check boundary conditions (equal) first.
    else if ((coordinateX == N - 1) && (coordinateY + 1 < N)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        cout << "current_cost " << current_cost << endl;
        int costIfGoesRight = INT_MAX;
        costIfGoesRight = recursive(coordinateX, coordinateY + 1);
        cout << "costIfGoesRight to " << coordinateX << " " << coordinateY + 1 << " " << costIfGoesRight << endl;
        // Bug: answer += is a bug. each recursive already returns currentValue + nextValue, there is no need for pre-increment
        // answer += current_cost + costIfGoesRight;
        answer = current_cost + costIfGoesRight;
    }
    else if ((coordinateX + 1 < N) && (coordinateY == N - 1)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        cout << "current_cost " << current_cost << endl;
        int costIfGoesDown = INT_MAX;
        costIfGoesDown = recursive(coordinateX + 1, coordinateY);
        cout << "costIfGoesDown to " << coordinateX + 1 << " " << coordinateY << " " << costIfGoesDown << endl;
        answer = current_cost + costIfGoesDown;
    }
    else if ((coordinateX + 1 < N) && (coordinateY + 1 < N)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        cout << "current_cost " << current_cost << endl;
        int costIfGoesDown = INT_MAX, costIfGoesRight = INT_MAX;
        costIfGoesDown = recursive(coordinateX + 1, coordinateY);
        cout << "costIfGoesDown to " << coordinateX + 1 << " " << coordinateY << " " << costIfGoesDown << endl;

        costIfGoesRight = recursive(coordinateX, coordinateY + 1);
        cout << "costIfGoesRight to " << coordinateX << " " << coordinateY + 1 << " " << costIfGoesRight << endl;;
        int next_cost = min(costIfGoesDown, costIfGoesRight);
        cout << " min of goes down vs goes right from " << coordinateX << " " << coordinateY << " " << next_cost << endl;
        answer = current_cost + next_cost;
    }
    return answer;
}

void Solve() {
    answer = recursive(0, 0);
}

void OutputData() {
    cout << answer << endl;
}

int main() {


    InputData();//	Input function

    //	Create the code
    Solve();

    OutputData();

    return 0;
}