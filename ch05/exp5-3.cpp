#include <iostream>
#include <set>
#include <sstream>

using namespace std;

/*
set的运用
s.size(); s.insert(x);
*/

// set中的内容自动按照字典序排序
set<string> dict;

int main()
{
    string s, buf;
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while (ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;
    return 0;
}