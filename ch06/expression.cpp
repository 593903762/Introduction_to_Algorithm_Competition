/*
表达式求值: 未对右括号进行判断，部分结果有误！
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

double expression_value();
double term_value();
double factor_value();

// 读入并计算表达式的值
double expression_value()
{
    double result = term_value();
    bool more = true;
    while (more)
    {
        char op = cin.peek();
        if (op == '+' || op == '-')
        {
            cin.get();
            double value = term_value();
            if (op == '+')
                result += value;
            else
                result -= value;
        }
        else
            more = false;
    }
    return result;
}

// 读入并计算项的值
double term_value()
{
    double result = factor_value();
    while (true)
    {
        char op = cin.peek();
        if (op == '*' || op == '/')
        {
            cin.get();
            double value = factor_value();
            if (op == '*')
                result *= value;
            else
                result /= value;
        }
        else
            break;
    }
    return result;
}

// 读入并计算因子的值
double factor_value()
{
    double result = 0;
    char c = cin.peek();
    if (c == '(')
    {
        cin.get();
        result = expression_value();
    }
    else
    {
        while (isdigit(c))
        {
            result = 10 * result + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}

int main()
{
    printf("%lf\n", expression_value());
    return 0;
}