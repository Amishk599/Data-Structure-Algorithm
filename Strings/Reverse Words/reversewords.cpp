#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string reverseWord(string word)
{
    string rev = "";
    int n = word.length();
    for (int i = n - 1; i >= 0; i--)
        rev += word[i];
    return rev;
}
int main()
{
    string str = "The quick fox jumped over the fence", reverse;
    cout << str << endl;
    istringstream iss(str);
    do
    {
        string word;
        iss >> word;
        reverse = reverse + " " + reverseWord(word);
    } while (iss);
    cout << reverse << endl;
    return 0;
}