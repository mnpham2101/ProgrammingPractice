#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

typedef long long llong;

int n;
llong v[30005], leftEarn[10005], rightEarn[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while(TC--) {
        cin >> n;
        for(int i=0; i<n; ++i) cin >> v[i];

        // solve
        auto minHeap = priority_queue<llong, vector<llong>, greater<llong>>();
        auto maxHeap = priority_queue<llong>();
        int minHeapMaxLen = 0;
        llong tot = 0, totMinHeap = 0;
        for(int i=0; i<n; ++i) {
            llong vi = v[i];

            if(i%3 == 0) {
                leftEarn[i/3] = tot - totMinHeap;
                minHeapMaxLen++;
            }

            tot += vi;

            if(minHeap.size() < minHeapMaxLen) {
                if(i==0 || maxHeap.top() < vi) {
                    minHeap.push(vi);
                    totMinHeap += vi;
                }
                else {
                    minHeap.push(maxHeap.top());
                    totMinHeap += maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(vi);
                }
            }
            else {
                if(minHeap.top() < vi) {
                    maxHeap.push(minHeap.top());
                    totMinHeap += vi - minHeap.top();
                    minHeap.pop();
                    minHeap.push(vi);
                }
                else {
                    maxHeap.push(vi);
                }
            }
        }

        minHeap = priority_queue<llong, vector<llong>, greater<llong>>();
        maxHeap = priority_queue<llong>();
        minHeapMaxLen = 0;
        tot = 0;
        totMinHeap = 0;
        for(int i=n-1; i>=0; --i) {
            llong vi = v[i];

            if(i%3 == 0) {
                rightEarn[i/3] = tot - totMinHeap;
                minHeapMaxLen++;
            }

            tot += vi;

            if(minHeap.size() < minHeapMaxLen) {
                if(i==n-1 || maxHeap.top() < vi) {
                    minHeap.push(vi);
                    totMinHeap += vi;
                }
                else {
                    minHeap.push(maxHeap.top());
                    totMinHeap += maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(vi);
                }
            }
            else {
                if(minHeap.top() < vi) {
                    maxHeap.push(minHeap.top());
                    totMinHeap += vi - minHeap.top();
                    minHeap.pop();
                    minHeap.push(vi);
                }
                else {
                    maxHeap.push(vi);
                }
            }
        }

        llong maxEarn = -1;
        int maxEarnIdx = -1;
        for(int i=0; i<n; i+=3) {
            llong curEarn = v[i] + leftEarn[i/3] + rightEarn[i/3];
            if(maxEarn < curEarn) {
                maxEarn = curEarn;
                maxEarnIdx = i;
            }
        }

        cout << maxEarnIdx << ' ' << maxEarn << '\n';
    }
}