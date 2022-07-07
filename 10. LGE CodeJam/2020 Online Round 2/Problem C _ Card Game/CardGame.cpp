#include <cstdio>
#define MAXN 30000

int main()
{
    int T, N, x;
    int i, j;
    int Min, Max;
    int Sum;
    int Up, Step;
    int ForAB[2][MAXN / 2];
    int ABIdx[2];
    int NIdx;
    int SizePreA;
    int SizePreB;
    int SizePostB;
    int NumA, NumB;
    int Offset;

    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &x);
        Sum = N * (N + 1) / 2;
        if (N % 2)
        {
            Min = (N + 1)*(N + 3) / 4 - Sum;
            Max = -1 * Min + 2;
        }
        else
        {
            Min = (N + 2)*(N + 4) / 4 - 2 - Sum;
            Max = Sum - N * (N + 2) / 4;
        }
        if ((Sum + x) % 2)
            printf("NO\n");
        else
        {
            if ((Min > x) || (Max < x))
                printf("NO\n");
            else if (N == 2)
            {
                printf("YES\n");
                printf("1 2\n");
            }
            else
            {
                Up = (x - Min) / 2;
                Step = (N - 1) / 2;
                ABIdx[0] = 0;
                ABIdx[1] = 0;
                NIdx = 1;
                NumA = (N + 1) / 2;
                NumB = N / 2;
                Offset = (N + 1) % 2;
                ForAB[Offset][ABIdx[Offset]++] = NIdx++;
                SizePreA = N / 2 - (Up + Step - 1) / Step;
                SizePreB = Up % Step;
                SizePostB = Step - Up % Step;

                for (j = 0; j < SizePreA; j++)
                    ForAB[0][ABIdx[0]++] = NIdx++;
                for (j = 0; j < SizePreB; j++)
                    ForAB[1][ABIdx[1]++] = NIdx++;
                if ((ABIdx[0] < NumA) && (SizePreB > 0))
                    ForAB[0][ABIdx[0]++] = NIdx++;
                for (j = 0; (j < SizePostB) && (ABIdx[1] < NumB); j++)
                    ForAB[1][ABIdx[1]++] = NIdx++;
                for (j = NIdx; j <= N; j++)
                    ForAB[0][ABIdx[0]++] = j;
                printf("YES\n");
                ABIdx[0] = 0;
                ABIdx[1] = 0;
                for (j = 0; j < N; j++)
                    printf("%d ", ForAB[(Offset + j) % 2][ABIdx[(Offset + j) % 2]++]);
                printf("\n");
            }
        }
    }
    return 0;
}