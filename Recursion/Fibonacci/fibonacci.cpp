#include <bits/stdc++.h>
using namespace std;
int fibonacci(int N)
{
    if (N < 2)
        return N;
    return fibonacci(N - 1) + fibonacci(N - 2);
}
int main()
{
    int element = 5 - 1;
    cout << fibonacci(element);
    return 0;
}