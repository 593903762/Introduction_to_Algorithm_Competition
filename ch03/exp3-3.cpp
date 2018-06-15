#include <stdio.h>
#include <cctype>
#include <cstring>

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome",
                     "a mirrored string", "a mirrored palindrome"};

char reverse(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while (scanf("%s", s) == 1)
    {
        int len = strlen(s);
        // p == 1 means palindrome; m = 1 means mirrored string.
        int p = 1, m = 1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != s[len - i - 1])
                p = 0;
            if (reverse(s[i]) != s[len - i - 1])
                m = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
    }
    return 0;
}