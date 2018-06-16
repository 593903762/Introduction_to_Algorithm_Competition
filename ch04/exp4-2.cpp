#include <stdio.h>
#include <cstring>

#define maxn 100

int main()
{
    int rnd;
    char s1[maxn], s2[maxn];
    while (scanf("%d%s%s", &rnd, s1, s2) == 3 && rnd != -1)
    {
        printf("Round %d\n", rnd);
        int win = 0, lose = 0, chance = 7;
        int len1 = strlen(s1), len2 = strlen(s2);
        // 还剩多少要猜
        int left = len1;
        for (int i = 0; i < len2; i++)
        {
            int guess_wrong = 1;
            for (int j = 0; j < len1; j++)
            {
                if (s1[j] == s2[i])
                {
                    left--;
                    s1[j] = ' ';
                    guess_wrong = 0;
                }
            }
            if (guess_wrong)
                --chance;
            if (!chance)
                lose = 1;
            if (!left)
                win = 1;
        }
        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}