#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * 例题6-5带指针的结构体双向链表的实现
 * 双向链表本身的构造应该没有问题，但实现有问题!
 */

// 定义双向链表
struct double_link_node
{
    int v;
    double_link_node *prev, *next;
    double_link_node(int v) : v(v), prev(NULL), next(NULL) {}
};
double_link_node *head;

// 连接两个结点(L在左，R在右)
void link(double_link_node *L, double_link_node *R)
{
    L->next = R;
    R->prev = L;
}

void initialize()
{
    head = new double_link_node(0);
    head->prev = NULL;
    head->next = NULL;
}

int n;
int main()
{
    int m, kase = 0;
    while (scanf("%d", &n) == 1)
    {
        initialize();
        // 完成初始链表的生成工作(采用头插法)
        // 链表的头结点和尾结点都是无意义的空结点
        double_link_node *first = new double_link_node(0);
        link(head, first);
        for (int i = n; i >= 1; i--)
        {
            double_link_node *cur = new double_link_node(i);
            /*
            first->prev = cur; cur->next = head->next;
            head->next = cur;  cur->prev = head;
             */
            link(head, cur);
            link(cur, first);
            first = first->prev;
        }
        int op, X, Y, inv = 0;
        while (m--)
        {
            scanf("%d", &op);
            if (op == 4)
                inv = !inv;
            else
            {
                scanf("%d%d", &X, &Y);
                // 找到值为X和Y的结点，分别将地址赋给X_node，Y_node
                double_link_node *X_node, *Y_node, *tmp = head->next;
                while (tmp->next)
                {
                    if (tmp->v == X)
                        X_node = tmp;
                    if (tmp->v == Y)
                        Y_node = tmp;
                    tmp = tmp->next;
                }
                // X和Y相邻，且X在Y的左边，那么直接交换X和Y的值即可达到目的(没有对别的结点造成任何影响)
                if (op == 3 && Y_node->next == X_node)
                    swap(X_node->v, Y_node->v);
                if (op != 3 && inv)
                    op = 3 - op;
                if (op == 1 && X_node == Y_node->prev)
                    continue;
                if (op == 2 && X_node == Y_node->next)
                    continue;

                double_link_node *LX_node = X_node->prev;
                double_link_node *RX_node = X_node->next;
                double_link_node *LY_node = Y_node->prev;
                double_link_node *RY_node = Y_node->next;
                if (op == 1)
                {
                    link(LX_node, RX_node);
                    link(LY_node, X_node);
                    link(X_node, Y_node);
                }
                else if (op == 2)
                {
                    link(LX_node, RX_node);
                    link(Y_node, X_node);
                    link(X_node, RY_node);
                }
                else if (op == 3)
                {
                    if (X_node->next == Y_node)
                    {
                        link(LX_node, Y_node);
                        link(Y_node, X_node);
                        link(X_node, RY_node);
                    }
                    else
                    {
                        link(LX_node, Y_node);
                        link(Y_node, RX_node);
                        link(LY_node, X_node);
                        link(X_node, RY_node);
                    }
                }
            }
        }
        /*
        double_link_node *it = head->next;
        long long ans = 0;
        int cnt = 1;
        while (it->next) {
            if (cnt % 2 == 1) ans += it->v;
            cnt++;
            it = it->next;
        }
        if (inv && n % 2 == 0) ans = (long long)n*(n+1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
         */
        // test
        double_link_node *tmp = head->next;
        while (tmp->next)
        {
            printf("%d ", tmp->v);
            tmp = tmp->next;
        }
        printf("\n");
    }
    return 0;
}