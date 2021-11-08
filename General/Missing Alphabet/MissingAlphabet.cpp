#include <bits/stdc++.h>
using namespace std;

set<char> missing;
void printMissingCharacters()
{
    if (missing.empty())
        cout << 0;
    else
        for (auto itr = missing.begin(); itr != missing.end(); itr++)
            cout << *itr;
}

void check(string str)
{
    for (char ch : str)
        if (missing.count(ch))
            missing.erase(missing.find(ch));
}

int main()
{
    char ch = 'a';
    string str = "The four boxing wizard starts over the quickly jmp";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    while (ch++ < 'z')
        missing.insert(ch);

    check(str);
    printMissingCharacters();

    return 0;
}