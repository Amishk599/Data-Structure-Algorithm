#include <bits/stdc++.h>
using namespace std;
string rotation(string str, int k)
{
    int n = str.size();
    string rot(n, 'x');
    for (int i = 0; i < n; i++)
    {
        int index = (i + k) % n;
        rot[index] = str[i];
    }
    return rot;
}
int check(string str, int k)
{
    int count = 0;
    istringstream iss(str);
    string word;
    do
    {
        iss >> word;
        string rot = rotation(word, k);
        if (word.compare(rot) == 0)
            count++;
        word.clear();
    } while (iss >> word);
    return count;
}
int main()
{
    int k = 5;
    string str = "Hello ofluxacine";
    cout << check(str, k);
    return 0;
}