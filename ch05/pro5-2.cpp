#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 15;
int a_cur[maxn], a_init[maxn];

int main()
{
    vector<int> v;
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a_cur[i]);
            v.push_back(a_cur[i]);
            a_init[i] = a_cur[i];
        }
        for (int t = 0; t < 1000; t++)
        {
            for (int i = 0; i < n; i++)
            {
                v[i] = abs(a_cur[i] - a_cur[(i + 1) % n]);
            }
            for (int i = 0; i < n; i++)
            {
                a_cur[i] = v[i];
            }
            int flag = 1, sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (a_cur[i] != a_init[i])
                    flag = 0;
                sum += a_cur[i];
            }
            if (flag)
            {
                printf("The Ducci sequence is cyclic!\n");
                break;
            }
            if (!sum)
            {
                printf("The Ducci sequence is 0.\n");
                break;
            }
        }
    }
    return 0;
}