#include <cstdio>
#include <algorithm>

#define MAXN 100000
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct
{
    int mIdx;
    int mSum;
}sSum;

bool compare(sSum a, sSum b){
    if(a.mSum > b.mSum)
        return TRUE;
    else
        return FALSE;
}
int main()
{
    int i, j;
    int T;
    int N;
    int AB[2][MAXN];
    sSum Sum[MAXN];
    long long SumAB[2];

    scanf("%d", &T);
    for( i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for( j = 0; j < N; j++)
        {
            scanf("%d %d", &AB[0][j], &AB[1][j]);
            Sum[j].mIdx = j;
            Sum[j].mSum = AB[0][j] + AB[1][j];
        }
        sort(Sum, Sum+N, compare);

        SumAB[0] = 0LL;
        SumAB[1] = 0LL;
        for( j = 0; j < N; j++)
        {
            SumAB[j%2] += (long long)(AB[j%2][Sum[j].mIdx]);
        }
        printf("%lld\n", SumAB[0] - SumAB[1]);
    }
    return 0;
}