#include <stdio.h>
#include <cstring>

#define maxn 85

int main()
{
    char s[maxn];
    while (scanf("%s", s) == 1)
    {
        int flag = 0, len = strlen(s);
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'O')
                flag += 1;
            else
                flag = 0;
            sum += flag;
        }
        printf("%d\n", sum);
    }
    return 0;
}