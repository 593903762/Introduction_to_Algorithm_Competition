/* 对计算数组元素之和的探讨 */
#include <stdio.h>

/* 错误 */
// 传入的a[]是一个地址（4字节）
int sum1(int a[])
{
    int ans = 0;
    printf("size of a = %d\n", sizeof(a));
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        ans += a[i];
    }
    return ans;
}

/* 正确 */
int sum2(int *a, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    return ans;
}

/* 正确 */
int sum3(int *begin, int *end)
{
    int ans = 0;
    int n = end - begin;
    for (int i = 0; i < n; i++)
    {
        ans += begin[i];
    }
    return ans;
}

/* 正确 */
int sum4(int *begin, int *end)
{
    int ans = 0;
    for (int *p = begin; p != end; p++)
    {
        ans += *p;
    }
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    printf("%d\n", sum4(a, a + 5));
    return 0;
}