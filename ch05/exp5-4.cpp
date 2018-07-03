#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
map???
m.push_back(x); m.count(x)
*/

map<string, int> cnts;
vector<string> dicts;

string standardization(const string &s)
{
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s[0] == '#')
            break;
        dicts.push_back(s);
        string r = standardization(s);
        if (!cnts.count(r))
            cnts[r] = 0;
        cnts[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < dicts.size(); i++)
    {
        if (cnts[standardization(dicts[i])] == 1)
            ans.push_back(dicts[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}