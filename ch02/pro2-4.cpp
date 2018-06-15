#include <stdio.h>

int main()
{
    long long n, m;
    int kase = 0;
    while (scanf("%lld%lld", &n, &m) == 2 && !(n == 0 && m == 0))
    {
        double sum = 0.0;
        for (int i = n; i <= m; i++)
        {
            // 避免溢出
            sum += (1.0 / i) * (1.0 / i);
        }
        printf("Kase %d: %.5f\n", ++kase, sum);
    }

    return 0;
}