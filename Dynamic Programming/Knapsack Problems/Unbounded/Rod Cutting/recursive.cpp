#include <bits/stdc++.h>
using namespace std;
int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
int N = sizeof(length) / sizeof(length[0]);

int findMaxProfit(int size, int N)
{
    if (size <= 0 || N < 0)
        return 0;

    if (length[N] > size)
        return findMaxProfit(size, N - 1);

    int profit1 = price[N] + findMaxProfit(size - length[N], N);
    int profit2 = findMaxProfit(size, N - 1);
    return max(profit1, profit2);
}
int main()
{

    int ans = findMaxProfit(N, N - 1);
    cout << ans;

    return 0;
}