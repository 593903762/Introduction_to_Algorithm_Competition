#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * 例题6-5双向链表的数组实现
 */

const int maxn = 100000 + 10;
int left[maxn], right[maxn];

void link(int L, int R)
{
    right[L] = R;
    left[R] = L;
}

int n;
int main()
{
    int m, kase = 0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        left[0] = n;
        right[0] = 1;
        int op, X, Y, inv = 0;

        while (m--)
        {
            scanf("%d", &op);
            if (op == 4)
                inv = !inv;
            else
            {
                scanf("%d%d", &X, &Y);
                // X和Y相邻，且X在Y的左边，那么直接交换X和Y的值即可达到目的(没有对别的结点造成任何影响)
                if (op == 3 && right[Y] == X)
                    swap(X, Y);
                if (op != 3 && inv)
                    op = 3 - op;
                // 以下讨论了两种特殊情况，二者的共同特点是相邻
                if (op == 1 && X == left[Y])
                    continue;
                if (op == 2 && X == right[Y])
                    continue;

                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if (op == 1)
                {
                    link(LX, RX);
                    link(LY, X);
                    link(X, Y);
                }
                else if (op == 2)
                {
                    link(LX, RX);
                    link(Y, X);
                    link(X, RY);
                }
                else if (op == 3)
                {
                    if (right[X] == Y)
                    {
                        link(LX, Y);
                        link(Y, X);
                        link(X, RY);
                    }
                    else
                    {
                        link(LX, Y);
                        link(Y, RX);
                        link(LY, X);
                        link(X, RY);
                    }
                }
            }
        }

        int b = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            b = right[b];
            if (i % 2 == 1)
                ans += b;
        }
        if (inv && n % 2 == 0)
            ans = (long long)n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}