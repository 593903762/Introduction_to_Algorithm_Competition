#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<string> words;
set<string> output;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            words.push_back(s);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string tmp = words[i] + words[j];
                vector<string>::iterator idx = find(words.begin(), words.end(), tmp);
                if (idx != words.end())
                    output.insert(tmp);

                tmp = words[j] + words[i];
                idx = find(words.begin(), words.end(), tmp);
                if (idx != words.end())
                    output.insert(tmp);
            }
        }

        cout << "The compound words are:\n";
        for (set<string>::iterator it = output.begin(); it != output.end(); it++)
            cout << *it << endl;
    }
    return 0;
}