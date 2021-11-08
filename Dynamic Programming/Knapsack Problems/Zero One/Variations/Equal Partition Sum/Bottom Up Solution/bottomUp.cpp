#include <bits/stdc++.h>
using namespace std;
int A[] = {5, 1, 11, 5, 1};
int N = sizeof(A) / sizeof(A[0]);
int dp[100][100];

int subsetSum(int sum)
{
    //initialization
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}
int main()
{
    int arr_sum = 0, sum, ans;
    //finding sum of the array
    for (int i = 0; i < N; i++)
        arr_sum += A[i];

    if (arr_sum % 2 != 0)
        ans = 0;
    else
    {
        sum = arr_sum / 2;
        ans = subsetSum(sum);
    }
    if (ans)
        cout << "yes, equal partition is possible" << endl;
    else
        cout << "no, equal partition is not possible" << endl;
    return 0;
}