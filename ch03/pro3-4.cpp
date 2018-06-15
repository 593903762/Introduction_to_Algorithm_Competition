#include <stdio.h>
#include <cstring>

#define maxn 85

int main()
{
    char s[maxn], tmp[maxn];
    while (scanf("%s", s) == 1)
    {
        int len = strlen(s);
        for (int i = 1; i <= len; i++)
        {
            if (len % i != 0)
                continue;
            int internal = 0, external = 0;
            for (int j = 0; j < i; j++)
                tmp[j] = s[j];
            int substring_num = len / i;
            for (int j = 1; j < substring_num; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (s[j * i + k] != tmp[k])
                    {
                        internal = 1;
                        break;
                    }
                }
                if (internal)
                {
                    external = 1;
                    break;
                }
            }
            if (!external)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}