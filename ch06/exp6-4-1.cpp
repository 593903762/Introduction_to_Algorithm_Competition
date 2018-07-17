#include <cstdio>
#include <cstring>

/**
 * 例题6-4带指针的结构体实现
 * */

const int maxn = 100000 + 5;
char s[maxn];

// 定义链表
struct link_node
{
    char v;
    link_node *next;
};
link_node *head, *cur, *tail;

void initialize()
{
    head = new link_node;
    head->next = NULL;
    cur = tail = head;
}

int main()
{
    while (scanf("%s", s) == 1)
    {
        initialize();
        int n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '[')
            {
                cur = head;
            }
            else if (ch == ']')
            {
                // 每次定位到尾结点的位置很麻烦
                link_node *tmp = head;
                while (tmp->next)
                    tmp = tmp->next;
                tail = tmp;
                cur = tail;
            }
            else
            {
                link_node *node = new link_node;
                node->v = ch;
                node->next = NULL;
                node->next = cur->next;
                cur->next = node;
                cur = cur->next;
            }
        }
        link_node *p = head->next;
        while (p)
        {
            printf("%c", p->v);
            p = p->next;
        }
        printf("\n");

        // 释放链表中各个结点的内存占用
        link_node *del = head->next;
        link_node *tmp = del->next;
        while (tmp)
        {
            delete del;
            del = tmp;
            tmp = tmp->next;
        }
        delete head;
    }
    return 0;
}