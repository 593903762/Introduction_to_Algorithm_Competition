#include <stdio.h>

int main()
{
    for (int n = 100; n <= 999; n++)
    {
        int x = n / 100;
        int y = n / 10 % 10;
        int z = n % 10;
        if (x * x * x + y * y * y + z * z * z == n)
            printf("%d\n", n);
    }
    return 0;
}