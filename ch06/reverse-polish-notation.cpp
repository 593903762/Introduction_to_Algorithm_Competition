#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

const int maxn = 40;
char s[maxn];

/*
 * 逆波兰表达式求值：递归
 */

double expr()
{
    cin >> s; // 自动过滤其中的空格
    switch (s[0])
    {
    case '+':
        return expr() + expr();
    case '-':
        return expr() - expr();
    case '*':
        return expr() * expr();
    case '/':
        return expr() / expr();
    default:
        return atof(s);
    }
}

int main()
{
    printf("%lf\n", expr());
    return 0;
}