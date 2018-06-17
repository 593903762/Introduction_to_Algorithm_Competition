#include <stdio.h>
#define maxn 25
int n, k, m;
int a[maxn];

// 从当前位置current开始，沿着direction方向走step步
int go(int current, int direction, int step)
{
    while (step--)
    {
        do
        {
            current = (current + n + direction - 1) % n + 1;
        } while (a[current] == 0);
    }
    return current;
}

int main()
{
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int left = n;
        // 本题最容易错的地方：A从1开始数，因此其初始位置为n；同理B初始位置为1
        int current_A = n, current_B = 1;
        while (left)
        {
            current_A = go(current_A, 1, k);
            current_B = go(current_B, -1, m);
            printf("%3d", current_A);
            left--;
            if (current_B != current_A)
            {
                printf("%3d", current_B);
                left--;
            }
            a[current_A] = a[current_B] = 0;
            if (left)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}