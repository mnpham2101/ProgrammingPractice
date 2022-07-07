#include <bits/stdc++.h>
using namespace std;

void test_case() {
    string S, C;
    cin >> S >> C;
              int n = S.length();
    int cursor = n; // Khoi tao con tro tai vi tri cuoi cung

    for(int i = 0; i < (int)C.length(); ++i) {
        if(C[i] == 'L') {
            if(cursor != 0)
                --cursor; // Neu con tro khong o vi tri dau thi giam chi so di 1
        }
        else if(C[i] == 'R') {
            if(cursor != n)
                ++cursor; // Neu con tro khong o vi tri cuoi thi tang chi so len 1
        }
        else if(C[i] == 'B') {
            if(cursor == 0)
                continue;  // Neu con tro nam o vi tri dau thi bo qua
            string tmp = "";
            for(int j = 0; j < n; ++j) {
                if(j != cursor - 1)
                    tmp += S[j];
            }
            --cursor;
            --n; // Giam do dai chuoi di 1
            S = tmp;
        }
        else {
            string tmp = "";
            for(int j = 0; j < cursor; ++j) {
                tmp += S[j];
            }
            tmp += C[i];
            for(int j = cursor;  j < n; ++j) {
                tmp += S[j];
            }
            ++cursor;
            ++n;
            S = tmp;
        }
    }

    cout << S << endl;
}

int main()
{
    test_case();
    return 0;
}