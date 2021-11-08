#include <bits/stdc++.h>
using namespace std;
#define MAX 10
//creating class
class Stack
{
public:
    int top;
    int arr[MAX];
    //default constructor
    Stack() { top = -1; }

    //push function
    void push(int value)
    {
        if (top >= MAX - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            arr[++top] = value;
            cout << value << " has been pushed" << endl;
        }
    }

    //pop function
    void pop()
    {
        if (top < 0)
            cout << "Stack Underflow" << endl;
        else
        {
            int value = arr[top--];
            cout << value << " has been popped" << endl;
        }
    }

    //peek function
    void peek()
    {
        if (top < 0)
            cout << "stack is empty" << endl;
        else
            cout << "elemet at top is " << arr[top] << endl;
    }

    //isEmpty function
    void isEmpty()
    {
        if (top < 0)
            cout << "stack is empty" << endl;
        else
            cout << "stck is not empty" << endl;
    }
};
int main()
{
    Stack stack;
    stack.isEmpty();
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.peek();
    stack.pop();
    stack.isEmpty();
    stack.peek();
    return 0;
}