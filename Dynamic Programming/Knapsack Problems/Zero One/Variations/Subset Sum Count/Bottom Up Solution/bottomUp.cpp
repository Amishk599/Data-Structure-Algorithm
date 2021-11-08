/*
arr[] = {2, 3, 5, 6, 8, 10}
sum = 10
Output: 3

            dp[]  [index]|  0    1    2    3    4    5    6    7    8    9   10  <- all possible sums
         ----------------|-----------------------------------------------------
   I          2     [0]  |  1    0    0    0    0    0    0    0    0    0    0  <- initialized 
   N          3     [1]  |  1    0    1    0    0    0    0    0    0    0    0    
   D          5     [2]  |  1    0    1    1    0    1    0    0    0    0    0    
   E          6     [3]  |  1    0    1    1    0    2    0    1    1    0    1    
   X          8     [4]  |  1    0    1    1    0    2    1    1    2    1    1    
             10     [5]  |  1    0    1    1    0    2    1    1    3    1    2
                    [6]  |  1    0    1    1    0    2    1    1    3    1   [3]

                            ^
                            |___ initialized
*/

#include <bits/stdc++.h>
using namespace std;
const int A[] = {2, 3, 5, 6, 8, 10};
const int N = sizeof(A) / sizeof(A[0]);
int dp[100][100];
int subsetSumCount(int sum)
{
    //initialization
    for (int i = 0; i <= sum; i++) // first row with 0s
        dp[0][i] = 0;

    for (int i = 0; i <= N; i++) // first column with 1s
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
void printMatrix(int a, int b)
{
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
            cout << dp[i][j] << "    ";
        cout << endl;
    }
}
int main()
{
    int ans, sum = 10;
    ans = subsetSumCount(sum);
    cout << "Number of subsets: " << ans << endl;
    printMatrix(N, sum);
    return 0;
}