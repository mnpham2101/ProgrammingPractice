#include<set>
#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int UP=0,RI=1,DN=2,LE=3;
int r, c;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char cost[512][512][4];
char dep[512][512];
int  pr[512][512], pc[512][512];
int edge[4][512*512][3];
int  ne[4];
pair<int, int> find_pare(int rr, int cc) {
    if(pr[rr][cc] == rr && pc[rr][cc] == cc) {
        return make_pair(rr,cc);
    }
    pair<int,int> p = find_pare(pr[rr][cc], pc[rr][cc]);
    pr[rr][cc] = p.first;
    pc[rr][cc] = p.second;
    return p;
}
int main() {
    int t;
    assert(1 == scanf("%d",&t));
    assert( 1 <= t && t <= 10);

    while(t--) {
        assert(2 == scanf("%d%d",&r,&c));
        assert(2 <= r && r <= 500);
        assert(2 <= c && c <= 500);
        memset(cost,0,sizeof(cost));
        memset(ne,0,sizeof(ne));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c-1; j++) {
                int x;
                assert(1 == scanf("%d",&x));
                assert(1 <= x && x <= 4);
                cost[i][j][RI] = cost[i][j+1][LE] = x;
                x--;
                edge[x][ne[x]][0] = i;
                edge[x][ne[x]][1] = j;
                edge[x][ne[x]][2] = RI;
                ne[x]++;
            }
        }
        for(int i = 0; i < r-1; i++) {
            for(int j = 0; j < c; j++) {
                int x;
                assert(1 == scanf("%d",&x));
                assert(1 <= x && x <= 4);
                cost[i][j][DN] = cost[i+1][j][UP] = x;
                x--;
                edge[x][ne[x]][0] = i;
                edge[x][ne[x]][1] = j;
                edge[x][ne[x]][2] = DN;
                ne[x]++;
            }
        }
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) {
            dep[i][j] = 1; pr[i][j] = i; pc[i][j] = j;
            int sum = 0;
            for(int k = 0; k < 4; k++)
                if(cost[i][j][k] != 0) {
                    assert(0 == (sum & (1<<cost[i][j][k])));
                    sum += (1<<cost[i][j][k]);
                }
        }
        // ------------------------------------------
        int cnt_edge = 0, tot_cost = 0;
        for(int x = 0; x < 4; x++) {
            for(int k = 0; k < ne[x] && cnt_edge < (r*c-1); k++) {
                int r1 = edge[x][k][0], c1 = edge[x][k][1];

                int r2 = r1 + dr[edge[x][k][2]], c2 = c1 + dc[edge[x][k][2]];
                pair<int, int> p1 = find_pare(r1, c1), p2 = find_pare(r2, c2);
                    fflush(stdout);
                if(p1 != p2) {
                    cnt_edge++;
                    tot_cost += (x+1);
                    if(dep[p1.first][p1.second] < dep[p2.first][p2.second]) {
                        pr[p1.first][p1.second] = p2.first;
                        pc[p1.first][p1.second] = p2.second;
                    }
                    else {
                        dep[p1.first][p1.second] += (dep[p1.first][p1.second] == dep[p2.first][p2.second]);
                        pr[p2.first][p2.second] = p1.first;
                        pc[p2.first][p2.second] = p1.second;
                    }
                }
            }
        }
        printf("%d\n", tot_cost);
    }
    return 0;
}