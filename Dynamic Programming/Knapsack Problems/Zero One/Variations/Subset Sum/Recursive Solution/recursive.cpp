//THIS SOLUTION CAN ONLY COUNT THE NUMBER OF SUBSETS THAT ADD UPTO THE SPECIFIED SUM

#include <bits/stdc++.h>
using namespace std;
//global varibles
const int A[] = {2, 3, 1, 4, 5, 7, 4, 3, 5};
const int N = sizeof(A) / sizeof(A[0]);
vector<vector<int>> ans;
int c = 0; //variable that stores the count of required subset

void recurse(int sum, int i, vector<int> subset)
{
    if (i > N || sum < 0) // i have no idea how i > N is working. I intially wrote i >= N
        return;

    if (sum == 0)
    {
        c++;
        return;
    }

    recurse(sum - A[i], i + 1, subset); //including the element
    recurse(sum, i + 1, subset);        //excluding the element
}

int main()
{
    int sum = 20;
    vector<int> subset;
    recurse(sum, 0, subset);
    cout << "The number of subsets: " << c;
    return 0;
}