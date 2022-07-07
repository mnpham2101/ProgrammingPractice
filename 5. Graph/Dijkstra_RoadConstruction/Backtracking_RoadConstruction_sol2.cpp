#include <iostream>
#include <climits>
using namespace std;

int r[] = {0, 1, 0, -1};
int c[] = {1, 0, -1, 0};

int N;//Map Size
char map[110][110];//Map information
int d[110][110];
bool visited[110][110];

void Input_Data(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}

void init() {  // Khởi tạo ma trận đường đi dự kiến và ma trận đã thăm.
    for(int i = 0; i < N; ++i)
        for (int j= 0; j < N; ++j) {
            visited[i][j] = false;  // Chưa đỉnh nào được thăm
            d[i][j] = INT_MAX;      // Đường đi chưa biết
        }
}

bool findMin(int& x, int& y) {  // Tìm đỉnh có đường đi ngắn nhất mà chưa được thăm
    int min = INT_MAX;
    int xmin, ymin;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j] && min > d[i][j]) {
                min = d[i][j];
                x = i;
                y = j;
            }
    return (min != INT_MAX);
}

void updateLocal(int x, int y) {  // Cập nhật đường đi tốt nhất cho đỉnh lân cận nếu đi qua (x,y) tốt hơn
    for (int i = 0; i < 4; ++i) {
        int newx = x + r[i];   // Tọa độ x lân cận
        int newy = y + c[i];   // Tọa độ y lân cận
        if (newx < 0 || newx >= N) continue;  // Tọa độ ngoài bản đồ
        if (newy < 0 || newy >= N) continue;  // Tọa độ ngoài bản đồ

        if (!visited[newx][newy] && d[newx][newy] > d[x][y] + (map[newx][newy] - '0') ) { // Nếu đi qua (x,y) tốt hơn hiện tại
            d[newx][newy] = d[x][y] + (map[newx][newy] - '0'); // Cập nhật giá trị mới cho đỉnh lân cận (x,y)
        }
    }
}

int main(){
    Input_Data();       //  Input function

    //  Write the code
    init();  // Khởi tạo ma trận d và visited

    d[0][0] = 0;  // Đường đi ngắn nhất tại điểm bắt đầu là 0.

    while (true) {  // Lặp cho đến khi tìm được đường đến đích
        int xmin, ymin;

        if (!findMin(xmin, ymin) || (xmin == N - 1 && ymin == N - 1)) { // Nếu không tìm được giá trị nhỏ nhất hoặc đỉnh nhỏ nhất là đỉnh đích (N-1, N-1)
            cout << d[N - 1][N-1] << endl;  //  Output answer
            return 0;
        }

        visited[xmin][ymin] = true;  // Đánh đấu đỉnh đã được thăm

        updateLocal(xmin, ymin);     // Cập nhật giá trị cho các đỉnh lân cân nếu tốt hơn

    }

    return 0;
}