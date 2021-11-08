#include <bits/stdc++.h>
using namespace std;
const int A[] = {3, 1, 4, 2, 2, 1};
const int N = sizeof(A) / sizeof(A[0]);
int dp[100][100];
vector<int> subsetSum(int sum)
{
    //initialization
    for (int i = 0; i <= sum; i++) //initializing the first row
        dp[0][i] = 0;

    for (int i = 0; i <= N; i++) //initializing the first column
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

    //extracting the valid set of sum values from the last row of the dp[][] matrix
    vector<int> v;
    for (int j = 0; j <= sum / 2; j++) // the range is from 0 -> sum/2 (both inclusive) | A way to optimize it is to largest valid 
    {
        if (dp[N][j] == 1) // if the corresponding sum value is possible i.e with value 1
            v.push_back(j);
    }
    return v;
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
    vector<int> val;
    int minimum = INT_MAX;
    int arr_sum = 0;
    //sum of array A[]
    for (int i = 0; i < N; i++)
        arr_sum += A[i];
    val = subsetSum(arr_sum);
    for (int i = 0; i < val.size(); i++)
    {
        int formula = arr_sum - (2 * val[i]);
        minimum = min(formula, minimum);
    }
    cout << "Minimum subset sum difference: " << minimum << endl;

    return 0;
}