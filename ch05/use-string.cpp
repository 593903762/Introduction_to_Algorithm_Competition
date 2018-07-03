#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// 从一行字符串中读取用空格分开的数字
// Attention! string & stringstream are very slow!

int main()
{
    string line;
    while (getline(cin, line))
    {
        int sum = 0, x;
        stringstream ss(line);
        while (ss >> x)
            sum += x;
        cout << sum << '\n';
    }
    return 0;
}