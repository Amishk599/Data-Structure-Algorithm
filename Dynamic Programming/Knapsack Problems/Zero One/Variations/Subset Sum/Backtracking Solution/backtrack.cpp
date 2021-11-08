#include <bits/stdc++.h>
using namespace std;
//global varibles
const int A[] = {2, 3, 1, 4, 5, 7, 4, 3, 5};
const int N = sizeof(A) / sizeof(A[0]);
vector<vector<int>> ans;
int c = 0;
//To see backtracking in action, call this function
void printVector(vector<int> v)
{
    for (auto ele : v)
        cout << ele << " ";
    cout << endl;
}
//printing the final result subsets
void printResultSubset(vector<vector<int>> V)
{
    for (int j = 0; j < V.size(); j++)
    {
        cout << "[";
        for (int i = 0; i < V[j].size(); i++)
        {
            if (i != V[j].size() - 1)
                cout << V[j][i] << ",";
            else
                cout << V[j][i];
        }
        cout << "]";
        if (j != V.size() - 1)
            cout << ", ";
        else
            cout << "";
    }
}

void findSubset(int sum, int start, vector<int> subset)
{
    if (sum < 0)
        return;

    if (sum == 0)
    {
        c++;
        ans.push_back(subset);
        return;
    }

    for (int i = start; i < N; i++)
    {
        subset.push_back(A[i]);
        //  printVector(subset);
        findSubset(sum - A[i], i + 1, subset);
        subset.pop_back();
    }
}
int main()
{
    int sum = 20;
    vector<int> subset;
    findSubset(sum, 0, subset);
    printResultSubset(ans);
    cout << endl
         << "Total subsets: " << c << endl;
    return 0;
}