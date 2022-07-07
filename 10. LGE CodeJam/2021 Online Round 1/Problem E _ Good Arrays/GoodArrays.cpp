#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int arr[1001][1001];
    arr[2][0] = 1;
    arr[2][1] = 2;
    for(int i=2;i<=1000;i++)
        arr[2][i] = 3;

    for(int i=3; i <= 1000; i++) {
        for(int j=0; j<=1000;j++) {
            arr[i][j] =  (j > 0 ? arr[i][j-1] : 0)
             + (arr[i-1][j] - ( j - i - 1  >= 0 ? arr[i-1][j - i - 1] : 0));
            if(arr[i][j] < 0)
                arr[i][j] += 1000000007;
            arr[i][j] %= 1000000007;
        }
    }
    while (t--) {
        int n,a,b;
        cin >> n >> a >> b;

        int ret = arr[n][b] - (a > 0 ? arr[n][a-1] : 0 );
        if(ret < 0){
            ret += 1000000007;
        }
        cout << ret << "\n";
    }
}