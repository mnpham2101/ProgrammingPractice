#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int answer = 0;
int N;               // map size 2<N<100
vector<vector<int>> landPrice;
vector<vector<int>> cache;

void InputData() {
    cin >> N;
    string input;

    // vector<vector<int>> landPrice(N, vector<int>(N));
    landPrice.resize(N, vector<int>(N));


    for (int i = 0; i < N; i++) {                               // O(N^2)
        cin >> input;
        for (int j = 0; j < N; j++) {
            landPrice[i][j] = input[j] - '0';
        }
    }
}

// use recursive call to traver all branches of decision tree and returns values 5/10 TC pass
int recursive(int coordinateX, int coordinateY, vector<vector<int>>& cache) {                          // O(N^2) ???? với N = tree depth ???

    // base case:
    if (coordinateX == N - 1 && coordinateY == N - 1) {
        return 0;
    }
    if (cache[coordinateX][coordinateY] != INT_MAX) {
        return cache[coordinateX][coordinateY];
    }
    // recursive cases: Note: the order of those conditions is paramount. Need to check boundary conditions (equal) first.
    else if ((coordinateX == N - 1) && (coordinateY + 1 < N)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        int costIfGoesRight = INT_MAX;
        costIfGoesRight = recursive(coordinateX, coordinateY + 1, cache);
        // Bug: answer += is a bug. each recursive already returns currentValue + nextValue, there is no need for pre-increment
        // answer += current_cost + costIfGoesRight;
        answer = current_cost + costIfGoesRight;
    }
    else if ((coordinateX + 1 < N) && (coordinateY == N - 1)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        int costIfGoesDown = INT_MAX;
        costIfGoesDown = recursive(coordinateX + 1, coordinateY, cache);
        answer = current_cost + costIfGoesDown;
    }
    else if ((coordinateX + 1 < N) && (coordinateY + 1 < N)) {
        int current_cost = landPrice[coordinateX][coordinateY];
        int costIfGoesDown = INT_MAX, costIfGoesRight = INT_MAX;
        costIfGoesDown = recursive(coordinateX + 1, coordinateY, cache);
        costIfGoesRight = recursive(coordinateX, coordinateY + 1, cache);
        int next_cost = min(costIfGoesDown, costIfGoesRight);
        answer = current_cost + next_cost;
    }
    cache[coordinateX][coordinateY] = answer;
    return answer;
}

void Solve() {
    cache.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {                  // O(N^2)
        for (int j = 0; j < N; j++) {
            cache[i][j] = INT_MAX;
        }
    }
    answer = recursive(0, 0, cache);
}

void OutputData() {
    cout << answer << endl;
}

int main() {
    InputData();//  Input function
    //  Create the code
    Solve();
    OutputData();
    return 0;
}