#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 每一位作者最多有100本书
const int maxn = 100;
map<string, int> authors;
vector<string> authors_name;
map<string, int> books[maxn];
vector<string> books_name[maxn];

// 为一个作者分配一个独一无二的ID
int ID_author(string name)
{
    if (authors.count(name))
        return authors[name];
    authors_name.push_back(name);
    return authors[name] = authors_name.size() - 1;
}

// 为每个不同的作者的每一本书分配唯一的ID
int ID_book(string name, int author)
{
    if (books[author].count(name))
        return books[author][name];
    books_name[author].push_back(name);
    return books[author][name] = books_name[author].size() - 1;
}

int main()
{
    string A, B;
    while (cin >> A && A != "END")
    {
        cin >> B;
        ID_book(A, ID_author(B));

        sort(authors_name.begin(), authors_name.end());
        for (int i = 0; i < authors_name.size(); i++)
            sort(books_name[i].begin(), books_name[i].end());
    }

    // 处理指令
    string ins;
    while (cin >> ins)
    {
        string book;
        if (ins != "SHELVE")
        {
            cin >> book;
            // 找到本书的作者
            int author;
            for (int i = 0; i < authors_name.size(); i++)
            {
                if (books[i].count(book))
                    author = i;
            }
            // 处理借书指令
            if (ins == "BORROW")
            {
            }
            else if (ins == "RETURN")
            {
            }
            else
                break;
        }
        else
        {
        }
    }

    return 0;
}