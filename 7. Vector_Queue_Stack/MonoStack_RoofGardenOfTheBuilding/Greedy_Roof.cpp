#include <iostream>
#include <stack>
using namespace std;

int N;//Number of buildings
int H[80010];//Height of buildings
stack<int> myStack; // Khai báo stack

void Input_Data(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }
}

int main(){
    long long ans = 0;
    Input_Data();       //  Input function

    //  Write the code
    H[N] = 1000000001;   // Thêm phần tử lính canh tại n với chiều cao lớn nhất có thể (có n+1) tòa nhà
    // Bước 1:
    myStack.push(0);     // Cho tòa nhà đầu tiên vào ngăn xếp
    for (int i = 1; i <= N; i ++) {       // Bắt đầu từ tòa nhà thứ hai (vị trí số 1) trở đi
        // Bước 2:
        if (H[i] >= H[myStack.top()]) {   // Nếu mà không thỏa mãn dãy giảm dần
            while (!myStack.empty() && H[i] >= H[myStack.top()]) {  // Tính toán các mái nhìn thấy được từ các tòa nhà bên trái tòa nhà vị trí i
                ans += i - myStack.top() - 1;                       // Cộng dồn kết quả lại
                myStack.pop();                                      // Loại bỏ khỏi stack để đảm bảo tính giảm dần
            }
        }
        // Bước 3:
        myStack.push(i);     // Thêm tòa nhà thứ i vào ngăn xếp
    }

    cout << ans << endl;    //  Output right answer
    return 0;
}