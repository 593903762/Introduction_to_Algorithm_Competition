#include <stdio.h>
#include <cstring>
#include <cstdlib>

#define maxn 105

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    char s1[maxn], s2[maxn];
    while (scanf("%s%s", s1, s2) == 2)
    {
        int yes = 1;
        int cnt1[26], cnt2[26];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int len = strlen(s1);
        for (int i = 0; i < len; i++)
        {
            cnt1[s1[i] - 'A']++;
            cnt2[s2[i] - 'A']++;
        }
        qsort(cnt1, 26, sizeof(int), cmp);
        qsort(cnt2, 26, sizeof(int), cmp);
        for (int i = 0; i < 26; i++)
        {
            if (cnt1[i] != cnt2[i])
            {
                yes = 0;
                break;
            }
        }
        if (yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}