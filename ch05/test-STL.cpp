#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <ctime>

using namespace std;

// 良好的习惯：将v作为引用参数写入参数列表中，而非用于返回值
// 避免不必要的复制
void fill_random_int(vector<int> &v, int cnt)
{
    v.clear();
    for (int i = 0; i < cnt; i++)
    {
        v.push_back(rand());
    }
}

void test_sort(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        // 宏：断言 (表达式为假时终止程序并给出提示)
        assert(v[i] <= v[i + 1]);
    }
}

int main()
{
    srand(time(NULL));
    vector<int> v;
    fill_random_int(v, 10);
    test_sort(v);

    return 0;
}