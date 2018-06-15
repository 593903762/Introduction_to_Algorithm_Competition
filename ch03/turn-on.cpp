/* 开灯问题 */
#include <stdio.h>
#include <cstring>

#define maxn 1005
int a[maxn];

int main()
{
    memset(a, 0, sizeof(a));
    int n, k;
    while (scanf("%d%d", &n, &k) == 2 && !(k == 0 && n == 0))
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (j % i == 0)
                    a[j] = !a[j];
            }
        }
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
                printf("%d ", i);
    }
    return 0;
}