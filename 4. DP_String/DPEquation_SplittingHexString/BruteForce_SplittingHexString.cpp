#include <iostream>
#include <string>
using namespace std;

int recursiveCall(string& originalString, int idx, string pre_val) {
    if (idx >= originalString.length())
        return 1;
    int ret = 0;
    for (int i = idx; i < originalString.length(); i++) {
        string currentSubstring = originalString.substr(idx, i - idx + 1);
        if (stoll(currentSubstring, nullptr, 16) >= stoll(pre_val, nullptr, 16)) {
            ret += recursiveCall(originalString, i + 1, currentSubstring);
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << recursiveCall(str, 0, "0") << endl;
    }
}