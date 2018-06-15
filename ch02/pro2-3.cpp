#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i - 1; j++)
                printf(" ");
            for (int j = 1; j <= 2 * (n + 1 - i) - 1; j++)
                printf("#");
            printf("\n");
        }
    }
    return 0;
}