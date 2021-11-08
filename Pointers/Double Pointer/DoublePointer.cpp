#include <bits/stdc++.h>
using namespace std;
void doublePointer(int **arr)
{
    cout << "&arr = " << &arr << endl;
    cout << "arr = " << arr << endl;
    cout << "*arr = " << *arr << endl;
    cout << "**arr = " << **arr << endl;
    cout << "*(*arr+3) = " << *(*arr + 3) << endl;
}
int main()
{
    int A[4][2] = {{9, 4}, {2, 6}, {8, 1}, {5, 7}};
    int *ptr = &A[0][0];
    doublePointer(&ptr);
    cout << "&A[0][0] = " << &A[0][0] << endl;
    cout << "&ptr = " << &ptr << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "*(ptr+2) = " << *(ptr + 2) << endl;
}