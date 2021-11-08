#include <bits/stdc++.h>
using namespace std;
string sent = "the take is care";
vector<string> input;
vector<vector<string>> ans;
void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void permutations(string str, int start, int end)
{
    if (start == end)
    {
        vector<string> v;
        for (char num : str)
        {
            int x = (int)num - 48;
            string word = sent[x];
            v.push_back(word);
        }
        ans.push_back(v);
        return;
    }
    for (int i = start; i < end; i++)
    {
        swap(str[start], str[i]);
        permutations(str, start + 1, end);
        swap(str[start], str[i]);
    }
}
int main()
{

    string alt = "";
    int end = input.size();
    //initialzing alt
    for (int i = 0; i < end; i++)
        alt += (char)i; //"012345"
    permutations(alt, 0, end);
    for (auto V : ans)
    {
        for (auto v : V)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}