#include <iostream>
using namespace std;
#define MAX 100001

int numbers[MAX];
bool mark[10];
int occurance[10], order[10];
int n,m, answer;

int calculate() {
    int result = 0;  // Số di chuyển ban đầu bằng 0
    int pos = 0;     // Vị trí của cấu hình mới được xây dựng
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < occurance[order[i]]; j ++,pos++ ) { // Lần lượt từng vị trí của cấu hình mới và so sánh với đầu bài
            if (numbers[pos] != order[i]) result ++; // Nếu giá trị khác nhau, số di chuyển tăng lên 1.
        }
    }
    return result; // Trả ra kết quả số lần di chuyển
}

void genarate(int i) {  // Sinh cấu hình sắp xếp thứ tự các loại hàng ở vị trí thứ i của cấu hình
    if (i > m) {  // Sinh đến phần tử cuối cùng của cấu hình
        int temp = calculate(); // Tính toán số lượng di chuyển cần thiết
        if (temp < answer)     // Ghi nhận kết quả tốt nhất.
            answer = temp;
        return;
    }
    // backtracking: tạo ra permutation của các cấu hình.
    for (int v = 1; v <= m; v ++) { // Tìm giá trị v cho cấu hình tiếp theo
        if (!mark[v]) {             // Nếu giá trị v chưa được chọn vào cấu hình
            mark[v] = true; // Chọn v là giá trị tiếp theo của cấu hình
            order[i] = v;
            genarate(i+1);  // Tiếp tục sinh cấu hình cho vị trí i + 1
            mark[v] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    answer = n + 1;
    int temp;
    for (int i = 0; i < n; i ++) {
        cin>>numbers[i];
        occurance[numbers[i]]++; // Đếm số phần tử của loại number thứ i
    }

    genarate(1); // Sinh cấu hình từ vị trí số 1

    cout<<answer;

    return 0;
}