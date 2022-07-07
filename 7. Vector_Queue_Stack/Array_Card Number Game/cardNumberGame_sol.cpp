#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

long long solve(string& x) {
    int n = x.size();
    vector<int> num;
    for (int i = 0; i < n; i++) {
        if (x[i] == '6')
            num.push_back(9);
        else
            num.push_back(x[i] - '0');
    }

    sort(num.rbegin(), num.rend());

    for (int i=0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }

    long long ans = 0;
    cout<<"(1 << n): "<<(1 << n)<<endl;
    vector <long long> v1List;
    vector <long long> v2List;
    vector <long long> ansList;
    for (int t = 0; t < (1 << n); t++) {
        long long v1 = 0, v2 = 0;
        for (int i = 0; i < n; i++) {
            if ((t & (1 << i)) == 0){
                v1 = v1 * 10ll + num[i];
                v1List.push_back(v1);
            }
            else{
                v2 = v2 * 10ll + num[i];
                v2List.push_back(v2);
            }
        }
        ans = max(ans, v1 * v2);
        ansList.push_back(ans);
    }
    cout<<"NumberA list:"<<endl;
    for (int i=0; i<num.size()-1; i++){
        cout<<v1List[i]<<" ";
    }
    cout<<endl;
    cout<<"NumberB list:"<<endl;
    for (int i=0; i<num.size()-1; i++){
        cout<<v2List[i]<<" ";
    }
    cout<<endl;
    cout<<"Ans list:"<<endl;
    for (int i=0; i<num.size()-1; i++){
        cout<<ansList[i]<<" ";
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    return 0;
}