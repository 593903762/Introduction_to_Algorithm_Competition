#include <stdio.h>

int main()
{
    long long a, b;
    int c;
    while (scanf("%lld%lld%d", &a, &b, &c) == 3 && !(a == 0 && b == 0 && c == 0))
    {
        printf("%lld.", a / b); //先输出整数部分和小数点
        a %= b;
        for (int i = 1; i < c; i++)
        { //输出除了最后一位以外的小数位
            printf("%lld", a * 10 / b);
            a = a * 10 % b;
        }
        // a * 10 % b是当前位的下一位，最后一位是否进行四舍五入是要看该位的后一位
        if (a * 10 % b * 10 / b < 5) //对需要输出的最后一位进行是否进位的判断
            printf("%lld", a * 10 / b);
        else
            printf("%lld", a * 10 / b + 1);
    }
    return 0;
}