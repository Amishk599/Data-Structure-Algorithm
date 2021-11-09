/*

Find all the groups of K consecutive equal characters and remove them. Determine the final word after all such groups are removed

example 1: 
word = "abbcccb"
k = 3
output  = "a"

example 2:
word = "aba"
k = 2
output = "aba"

example 3:
word = "baac"
k = 2
output = "bc"

*/

#include <bits/stdc++.h>
using namespace std;

bool checkRepetition(string word)
{
    for (int i = 1; i < word.size(); i++)
        if (word[i] != word[0])
            return false;
    return true;
}
string compressWord(string word, int k, int i)
{
    if (word.size() <= k || i + k - 1 >= word.size())
        return word;

    string subString = word.substr(i, k);
    if (checkRepetition(subString))
    {
        word.erase(i, k);
        word = compressWord(word, k, 0);
    }
    else
        word = compressWord(word, k, i + 1);

    return word;
}

int main()
{
    string word = "abbcccb";
    int k = 3;
    cout << "Final word: " << compressWord(word, k, 0);
    return 0;
}