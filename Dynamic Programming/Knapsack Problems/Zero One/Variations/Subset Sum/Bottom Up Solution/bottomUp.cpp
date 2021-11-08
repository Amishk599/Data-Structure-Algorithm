/*
arr[] = {2, 3, 7, 8, 10}
sum = 11
Output: 1


            dp[]  [index]|  0    1    2    3    4    5    6    7    8    9   10   11   <- all possible sums
         ----------------|----------------------------------------------------------
    I        2      [0]  |  1    0    0    0    0    0    0    0    0    0    0    0   <-- initialized
    N        3      [1]  |  1    0    1    0    0    0    0    0    0    0    0    0
    D        7      [2]  |  1    0    1    1    0    1    0    0    0    0    0    0
    E        8      [3]  |  1    0    1    1    0    1    0    1    0    1    1    0
    X        10     [4]  |  1    0    1    1    0    1    0    1    1    1    1    1    
    S               [5]  |  1    0    1    1    0    1    0    1    1    1    1   [1]
                            ^
                            |___ initialized

say we're at cell indexed i = 4, j = 4
this means - can we add 3rd number (i.e 8) when sum is 4
    is 8 <= 4 ---> no it is not
        dp[4][4] = dp[3][4] = 0 means no

say we're at cell indexed i = 3, j = 2
this means - can we add 2nd number (i.e 7) when sum is 2
    is 7 <= 2 ---> no it is not
        dp[3][2] = dp[2][2] = 0 means no

say we're at cell indexed i = 1, j = 2
this means - can we add 0th number (i.e 2) when sum is 2
    is 2 <= 2 ---> yes it is possible
        dp[1][2] = (dp[0][2-2]) || (dp[0][2])  ----> either we can choose it or we can skip it
                 = (dp[0][0]) || (dp[0][2])
                 = 1 || 0
                 = 1 = which means yes
*/

#include <bits/stdc++.h>
using namespace std;
bool dp[20][21];
int bottomUp(int arr[], int N, int sum)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if the number at i-1 index smaller than j then we can either choose to pick it or skip it.
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
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
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int N = sizeof(arr) / sizeof(arr[0]);

    //filling the first column with 0s
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;

    //filling the first row with 0s
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;

    bool ans = bottomUp(arr, N, sum);
    cout << "Ans: " << ans << endl;
    printMatrix(N, sum);
    return 0;
}