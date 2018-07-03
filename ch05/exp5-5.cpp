#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache; // 将集合映射为ID
vector<Set> Setcache;  // 存放集合的大集合，Setcache[IDcache[s]]存放着s本身

/*
 * 重点！对复杂变量（如字符串）分配新的编号作为其标志
 */
int ID(Set x)
{
    if (IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op[0] == 'P')
            s.push(ID(Set()));
        else if (op[0] == 'D')
            s.push(s.top());
        else
        {
            Set x1 = Setcache[s.top()];
            s.pop();
            Set x2 = Setcache[s.top()];
            s.top();
            Set x;
            if (op[0] == 'U')
                set_union(ALL(x1), ALL(x2), INS(x));
            if (op[0] == 'I')
                set_intersection(ALL(x1), ALL(x2), INS(x));
            if (op[0] == 'A')
            {
                x = x2;
                x.insert((ID(x1)));
            }
            s.push(ID(x));
        }
        cout << Setcache[s.top()].size() << endl;
    }
    return 0;
}