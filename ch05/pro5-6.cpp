#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000;
vector<int> points[maxn];
int a[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        int flag = 1;
        // 数组预先设置的值必须不能被任意点的y值取到，否则Line30寻找idx会出错
        memset(a, maxn, sizeof(a));
        set<int> diff_y;
        int x, y, kase = -1, axis = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            if (!diff_y.count(y))
            {
                diff_y.insert(y);
                kase++;
                points[kase].push_back(x);
                a[kase] = y;
            }
            else
            {
                int idx = find(a, a + n, y) - a;
                points[idx].push_back(x);
            }
            axis += x;
        }

        for (int i = 0; i < kase; i++)
        {
            int sum_y;
            vector<int>::iterator it = points[i].begin();
            while (it != points[i].end())
                sum_y += *it++;
            if (sum_y / points[i].size() != axis / n)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}