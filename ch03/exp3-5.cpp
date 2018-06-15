/* 方法1
#include <stdio.h>

int main()
{
    int x, y;
    while (scanf("%d", &y) == 1 && y != 0)
    {
        int flag = 0;
        for (x = 1; x < y; x++)
        {
            int x0 = x;
            int sum = x0;
            while (x0 > 0)
            {
                sum += x0 % 10;
                x0 /= 10;
            }
            if (sum == y)
            {
                printf("%d\n", x);
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("0\n");
    }
    return 0;
}
*/

/* 方法二 */
#include <stdio.h>
#include <cstring>

#define maxn 100005
int ans[maxn];

int main()
{
    int n;
    memset(ans, 0, sizeof(ans));
    for (int m = 1; m < maxn; m++)
    {
        int x = m, y = m;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || m < ans[y])
            ans[y] = m;
    }
    while (scanf("%d", &n) == 1 && n != 0)
        printf("%d", ans[n]);
    return 0;
}