/*
input: 16748 | N = 2
output: 164

-remove N elements and make the smallest possible number
-do not change the order of the remaining numbers
*/
#include <bits/stdc++.h>
using namespace std;
string makeLargest(string str, int N)
{
    string s = str, eli = "";
    int len = str.length();
    sort(s.begin(), s.end());
    eli = s.substr(len - N); //string containing the numbers to be removed - largest
    for (char ch : eli)
    {
        int x = str.find(ch);
        str.erase(x, 1);
    }
    return str;
}
int main()
{
    string str = "1004";
    int N = 1;
    cout << makeLargest(str, N);
    return 0;
}