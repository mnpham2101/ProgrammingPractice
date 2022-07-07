#include <iostream>
using namespace std;
#define MAX 100001

int numbers[MAX][10]; // Lưu trữ số phần tử từ đầu mảng gốc của từng vị trí.
bool mark[10];
int occurance[10], order[10];
int n,m, answer;

// For each permumation config of product types, perform sliding windows
int calculate() {
    int result = 0;
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        int num = order[i]; //Con số đang xét num
        pos += occurance[num];  // Khoảng đang xét là count[num] vị trí liên tiêp từ (pos - count[num],pos]

        // Số di chuyển cần thiết là lấy số phần tử của num trừ đi số phần tử của num có trong mảng gốc trong nửa đoạn (pos - count[num],pos]
        result += occurance[num] - (numbers[pos][num] - numbers[pos - occurance[num]][num]);
    }
    return result;
}

// backtracking algo to generate permutation of product types
void genarate(int i) {
    if (i > m) {
        int temp = calculate();
        if (temp < answer)
            answer = temp;
        return;
    }

    for (int v = 1; v <= m; v ++) {
        if (!mark[v]) {
            mark[v] = true;
            order[i] = v;
            genarate(i+1);
            mark[v] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    answer = n + 1;
    int temp;
    // lưu giữ liệu và tạo 2D array để save số lượng các phần tử cùng productType tính từ vị trí đầu đến một vị trí bất kỳ
    for (int i = 1; i <= n; i ++) {
        cin>>temp;
        for (int j = 1; j <= m; j ++)  // Lưu số phần tử từng vị trị từ 1 -> M
            numbers[i][j] = numbers[i-1][j]; // Số lượng phần tử bằng số lượng ngay trước nó.

        numbers[i][temp] ++;          // Tăng số lượng tại vị trí i của temp lên 1.
        occurance[temp]++;                // Đếm số phần tử
    }


    genarate(1);

    cout<<answer;

    return 0;
}