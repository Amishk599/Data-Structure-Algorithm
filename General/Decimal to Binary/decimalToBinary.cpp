#include <bits/stdc++.h>
using namespace std;
string binaryToDecimal(int num)
{
    string str = "";
    while (num)
    {
        char bit = (char)(num % 2 + 48);
        str = bit + str;
        num /= 2;
    }

    return str;
}
int maxGap(string binary)
{
    int start, end, size, max_gap;
    start = 0;
    size = binary.length();
    max_gap = 0;

    while (binary[start] != '1')
        start++;
    end = start + 1;

    while (end < size)
    {
        if (binary[end] == '1')
        {
            int gap = end - start - 1;
            max_gap = max(gap, max_gap);
            start = end;
        }
        end++;
    }
    return max_gap;
}
int main()
{
    int num = 32;
    string binary = binaryToDecimal(num);
    cout << "Decimal number: " << num << endl;
    cout << "Binary equivalent: " << binary << endl;
    cout << "Max binary gap: " << maxGap(binary);
    return 0;
}