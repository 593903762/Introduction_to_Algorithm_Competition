#include <cstdio>
#include <cstring>

/**
 * 例题6-4链表的数组实现
 * */

const int maxn = 100000 + 5;
char s[maxn];
int last, cur, next[maxn];

int main()
{
    while (scanf("%s", s + 1) == 1)
    {
        int n = strlen(s + 1);
        // initialize
        last = cur = 0;
        next[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch = s[i];
            if (ch == '[')
                cur = 0;
            else if (ch == ']')
                cur = last;
            else
            {
                next[i] = next[cur];
                next[cur] = i; // 这两步完成了结点插入的操作
                // last的更新操作，为什么比带指针的链表容易很多？
                // 这是因为整个“链表”的结构根本没有发生变化！s还是那个s，变得仅有自己定义的某个顺序(next)
                if (cur == last)
                    last = i;
                cur = i; // 相当于cur = cur->next
            }
        }
        for (int i = next[0]; i != 0; i = next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}