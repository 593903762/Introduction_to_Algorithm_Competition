#include <iostream>
#include <cstdlib>
#include <memory>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 105
const char para[4] = {'C', 'H', 'N', 'O'};
const double mass[] = {12.01, 1.008, 16.00, 14.01};
int num[4] = {0, 0, 0, 0};
double answer[maxn];

int main()
{
    memset(answer, 0, sizeof(answer));
    int kase;
    cin >> kase;
    for (int time = 0; time < kase; time++)
    {
        char c;
        int last;
        while ((c = getchar()) != '\n')
        {
            if (isalpha(c))
            {
                for (int i = 0; i < 4; i++)
                {
                    if (c == para[i])
                    {
                        num[i]++;
                        last = i;
                    }
                }
            }
            else
            {
                int tmp = c - '0';
                char d;
                while ((d = getchar()) != '\n')
                {
                    if (isalpha(d))
                    {
                        ugetc(d, stdin); // 不存在ugetc这个函数？？
                        break;
                    }
                    else
                        tmp = 10 * tmp + d - '0';
                }
                num[last] = num[last] + tmp - 1;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            answer[time] += num[i] * mass[i];
        }
        printf("%.3f\n", answer[time]);
    }
    return 0;
}