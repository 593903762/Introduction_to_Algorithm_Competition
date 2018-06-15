/* 蛇形填数 */
#include <stdio.h>
#include <cstring>

#define maxn 20
int a[maxn][maxn];

int main()
{
    memset(a, 0, sizeof(a));
    // memcpy(b, a, sizeof(a)); memcpy(b, a, sizeof(int)*k)也需要掌握，常用
    int n, x, y, value;
    scanf("%d", &n);

    value = a[x = 0][y = n - 1] = 1;
    while (value < n * n)
    {
        while (x + 1 < n && !a[x + 1][y])
            a[++x][y] = ++value;
        while (y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = ++value;
        while (x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = ++value;
        while (y + 1 < n && !a[x][y + 1])
            a[x][++y] = ++value;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}