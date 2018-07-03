#include <cstdio>
#include <map>

using namespace std;

const int maxn = 500000;
map<int, int> dicts;
int a[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        int B;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i], &B);
            dicts[a[i]] = B;
        }
        for (int i = 0; i < dicts.size() - 1; i++)
        {
            for (int j = i + 1; j < dicts.size(); j++)
            {
                if (dicts[a[i]] == a[j] && dicts[a[j]] == a[i])
                {
                    dicts[a[i]] = dicts[a[j]] = 0;
                }
            }
        }
        int value_sum = 0;
        for (int i = 0; i < dicts.size(); i++)
            value_sum += dicts[a[i]];
        if (!value_sum)
            printf("Exchange can be conducted!\n");
        else
            printf("Exchange can not be conducted!\n");
    }
    return 0;
}