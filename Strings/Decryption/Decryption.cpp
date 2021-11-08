/*
Decrypt the encrypted string
input: a1b3c4d2e6
output: abbbccccddeeeeee  

input: mnop5qrs7
ouput: mnopmnopmnopmnopmnopqrsqrsqrsqrsqrsqrsqrs
*/

#include <bits/stdc++.h>
using namespace std;

string decrypt(string str)
{
    int i = 0, start = 0;
    string num_str = "", ans = "";
    while (i < str.size())
    {
        if (str[i] > '0' && str[i] < '9')
        {
            while ((str[i] > '0' && str[i] < '9') && i < str.size())
            {
                num_str += str[i];
                i++;
            }
        } //if
        if (!num_str.empty())
        {
            int end = str.find(num_str);
            string substring = str.substr(start, end - start);
            int num = stoi(num_str);
            for (int i = 1; i <= num; i++)
                ans += substring;
            start = i;
            num_str.erase();
            i--;
        }
        i++;
    }
    return ans;
}
int main()
{
    string encry = "a1b3c4d2e6";
    // string encry = "mnop5qrs7";
    cout << decrypt(encry);
    return 0;
}