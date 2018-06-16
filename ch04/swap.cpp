/* 对函数参数的探讨 */
#include <stdio.h>
/* 错误 */
void swap1(int *a, int *b)
{
    int *t = a;
    a = b;
    b = t;
}

/* 错误 */
// t在赋值前地址未知，这个地址不一定是可以写的（实际上，这个未知的地址几乎都是不可写的
void swap2(int *a, int *b)
{
    int *t;
    *t = *a;
    *a = *b;
    *b = *t;
}

/* 正确 */
void swap3(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a = 3, b = 4;
    swap3(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}