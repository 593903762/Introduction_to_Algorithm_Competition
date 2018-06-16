#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

#define maxn 85
using namespace std;

vector<int> positions[maxn];
char s[maxn], t[maxn];

int main()
{
    int next_round = 0;
    while (scanf("%s%s", s, t) == 2)
    {
        int yes = 1;
        int s_len = strlen(s), t_len = strlen(t);
        for (int i = 0; i < t_len; i++)
        {
            for (int j = 0; j < s_len; j++)
            {
                if (t[i] == s[j])
                    positions[i].push_back(j);
            }
            if (positions[i].size() == 0)
            {
                printf("No");
                next_round = 1;
                break;
            }
        }
        if (next_round)
        {
            next_round = 0;
            continue;
        }
        for (int i = 0; i < t_len - 1; i++)
        {
            int now = *min_element(positions[i].begin(), positions[i].end());
            int after = *max_element(positions[i + 1].begin(), positions[i + 1].end());
            if (now >= after)
            {
                yes = 0;
                break;
            }
        }
        if (yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}