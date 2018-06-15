#include <stdio.h>

int main()
{
    int a, b, c;
    int kase = 0;
    while (scanf("%d%d%d", &a, &b, &c) == 3 && !(a == 0 && b == 0 && c == 0))
    {
        int flag = 0;
        for (int n = 10; n <= 100; n++)
        {
            if (n % 3 == a && n % 5 == b && n % 7 == c)
            {
                printf("Case %d: %d\n", ++kase, n);
                flag = 1;
            }
        }
        if (!flag)
            printf("Case %d: No answer\n", ++kase);
    }
    return 0;
}