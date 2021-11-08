#include <bits/stdc++.h>
using namespace std;
const int A[] = {1, 1, 2, 3};
const int diff = 1;
const int N = sizeof(A) / sizeof(A[0]);
int dp[100][100];
void initializeDP(int arr_sum)
{
    //initalizing the first row
    for (int i = 0; i <= arr_sum; i++)
        dp[0][i] = 0;
    //initalizing the first column
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= arr_sum; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}
int countSubsetSum(int sum)
{
    int dp[N + 1][sum + 1];
    //initalizing the first row
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    //initalizing the first column
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}
int main()
{

    int arr_sum = 0, s1, s2;
    //sum of array elements
    for (int i = 0; i < N; i++)
        arr_sum += A[i];
    initializeDP(arr_sum);
    //potential values of s1
    for (int i = 0; i <= arr_sum / 2; i++)
    {
        if (dp[N][i] == 1)
        {
            s1 = i;
            s2 = arr_sum - s1;
            if (s2 - s1 == diff)
                break; //after breaking out of this loop s1 and s2 will have suitable values
        }
    }
    int count = countSubsetSum(s1);
    cout << "Number of instances when subset sum 1 - subset sum 2 = given difference: " << count;
    return 0;
}