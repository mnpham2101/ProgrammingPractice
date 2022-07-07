#include <iostream>
using namespace std;

int N;//The number of goods to send
int C[10];//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10];//The number of boxes to send
int Size[] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000}; // Size của từng loại hộp

void InputData(){
    int i;
    cin >> N;
    for(i = 0; i < 10; i++){
        cin >> C[i];
    }
}
void OutputData(int ans){
    int i;
    cout << ans << endl;
    for(i = 0; i < 10; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool pack(int& numberOfGoods, int& boxType) {  // Đóng gói số lượng hàng hóa numberOfGoods vào loại hộp boxType
    if (numberOfGoods < Size[boxType] && sol[boxType] < C[boxType])  // Nếu số lượng hàng hóa nhỏ hơn size của hộp và đồng thời vẫn còn hộp loại đó thì không đóng gói được
        return false;
    if (sol[boxType] == C[boxType])  // Nếu loại hộp hết, thì chuyển sang loại hộp tiếp theo
        ++boxType;
    else {
        numberOfGoods -= Size[boxType];  // Đóng gói vào hộp
        ++ sol[boxType];                 // Tăng số lượng hộp lên
    }
    return true;                         // Thông báo đóng gói thành công
}

void adjustBox(int& numberOfGoods, int targetBox, int sourceBox) {   // Điều chỉnh hàng hóa cho khít số lượng hàng hóa của loại hộp target bằng cách bỏ số hàng hóa từ loại hộp source đã đóng gói ra
    while (sol[sourceBox] > 0 && numberOfGoods + Size[sourceBox] <= Size[targetBox]) { // Nếu hàng hóa đã đóng gói của loại source vẫn còn và hàng hóa bỏ ra vẫn chưa quá sức chứa của loại hộp target
        --sol[sourceBox];                  // Bỏ một hộp đã đóng gói của loại source đi
        numberOfGoods += Size[sourceBox];  // Tăng số lượng hàng hóa đang có lên
    }
    if (numberOfGoods != Size[targetBox])  // Nếu số lượng hàng hóa đang có chưa đủ để đóng gói loại hộp target, lấy thêm hàng hóa từ những loại hộp nhỏ hơn đã được đóng gói
        adjustBox(numberOfGoods, targetBox, sourceBox - 1);
}

int main(){
    int ans = 0;

    InputData();//  Input function

    //  Create the code
    int boxType = 0;  // Bắt đầu đóng gói từ loại hộp đầu tiên (1 đơn vị)
    while (N > 0) {   // Khi nào vẫn chưa đóng gói xong
        if (!pack(N, boxType)) {  // Thử đóng gói mà không được
            adjustBox(N, boxType, boxType -1); // Điều chỉnh bằng cách lấy thêm hàng hóa từ những loại hộp đã được đóng gói trước đó.
        }
    }

    for (int i = 0; i < 10; ++i) // Đếm số lượng hộp đã đóng gói
        ans += sol[i];

    OutputData(ans);//  Output function

    return 0;
}