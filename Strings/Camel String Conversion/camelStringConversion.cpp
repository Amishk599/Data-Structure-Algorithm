#include <bits/stdc++.h>
using namespace std;
void convert(string str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        int c = (int)str[i];
        if (c >= 65 && c <= 90)
        {
            ans += ' ';
            ans += (char)(c + 32);
        }
        else
            ans += (char)c;
    }
    ans.erase(ans.begin());
    cout << ans;
}
int main()
{
    string str;
    cin >> str;
    convert(str);
    return 0;
}
