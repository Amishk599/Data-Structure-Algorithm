
#include <bits/stdc++.h>
using namespace std;
string rotateLeft(int N, string str)
{
    int i, j;
    N = N % str.size();
    i = 0;
    j = i + N;
    string buffer = "";

    for (int k = i; k < j; k++)
        buffer += str[k];

    while (j < str.size())
        str[i++] = str[j++];

    str.erase(str.end() - N, str.end());
    str = str + buffer;

    return str;
}

string rotateRight(int N, string str)
{
    int i, j;
    N = N % str.size();
    j = str.size() - 1;
    i = j - N;
    string buffer = "";

    for (int k = i + 1; k <= j; k++)
        buffer += str[k];

    while (i >= 0)
        str[j--] = str[i--];

    str.erase(str.begin(), str.begin() + N);
    str = buffer + str;

    return str;
}
int main()
{
    int N = 2;
    string str = "PARIS";
    cout << "Right Rotation: " << rotateRight(N, str) << endl;
    cout << "Left Rotation: " << rotateLeft(N, str) << endl;

    return 0;
}

///////////////////////////////////////

vector<string> substr;
void print()
{
    for (auto itr : substr)
        cout << itr << " ";
}
void substrings(string ip, string op)
{
    if (ip.size() == 0)
    {
        substr.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    substrings(ip, op1);
    substrings(ip, op2);
}
int main()
{
    int N = 2;
    string str = "ABC";
    cout << "Right Rotation: " << rotateRight(N, str) << endl;
    cout << "Left Rotation: " << rotateLeft(N, str) << endl;
    substrings(str, "");
    print();

    return 0;
}