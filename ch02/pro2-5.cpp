#include <stdio.h>

int main()
{
    long long a, b;
    int c;
    while (scanf("%lld%lld%d", &a, &b, &c) == 3 && !(a == 0 && b == 0 && c == 0))
    {
        printf("%lld.", a / b); //������������ֺ�С����
        a %= b;
        for (int i = 1; i < c; i++)
        { //����������һλ�����С��λ
            printf("%lld", a * 10 / b);
            a = a * 10 % b;
        }
        // a * 10 % b�ǵ�ǰλ����һλ�����һλ�Ƿ��������������Ҫ����λ�ĺ�һλ
        if (a * 10 % b * 10 / b < 5) //����Ҫ��������һλ�����Ƿ��λ���ж�
            printf("%lld", a * 10 / b);
        else
            printf("%lld", a * 10 / b + 1);
    }
    return 0;
}