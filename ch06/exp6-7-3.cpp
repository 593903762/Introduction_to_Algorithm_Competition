#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100010;

/**
 * 树结构的结构体数组实现（动态+静态）
 * 借助动态内存池技术，不对内存造成浪费
 * */
struct Node
{
    bool have_value;
    int v;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {}
};
Node *root;

//**内存池技术**
queue<Node *> freeNode; // 空闲列表
Node nodes[maxn];

// 将结构体数组中所有空闲的元素位置的指针存入空闲列表
void init()
{
    for (int i = 0; i < maxn; i++)
        freeNode.push(&nodes[i]);
}

// 依次从空闲列表中取出空闲位置
Node *new_node()
{
    Node *u = freeNode.front();
    u->left = u->right = NULL;
    u->have_value = false;
    freeNode.pop();
    return u;
}

// 将弃置元素的地址回收如空闲列表即可
void delete_node(Node *u)
{
    freeNode.push(u);
}

bool failed;
void add_node(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = new_node();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = new_node();
            u = u->right;
        }
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
}

void remove_tree(Node *u)
{
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete_node(u);
}

char s[maxn];
bool read_input()
{
    failed = false;
    remove_tree(root);
    root = new_node();
    for (;;)
    {
        if (scanf("%s", s) != 1)
            return false;
        // strcmp(s1, s2): s1 == s2: return 0; s1 > s2: return 1.
        if (!strcmp(s, "()"))
            break;
        int v;
        sscanf(&s[1], "%d", &v);
        add_node(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while (!q.empty())
    {
        Node *u = q.front();
        q.pop();
        if (!u->have_value)
            return false;
        ans.push_back(u->v);
        if (u->left != NULL)
            q.push(u->left);
        if (u->right != NULL)
            q.push(u->right);
    }
    return true;
}

int main()
{
    vector<int> ans;
    while (read_input())
    {
        // failed存在两种可能，其一是：至少存在一个结点被多次赋值
        // 其二是：至少存在一个结点没有被赋值
        if (!bfs(ans))
            failed = true;
        if (failed)
            printf("-1\n");
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (i != 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
