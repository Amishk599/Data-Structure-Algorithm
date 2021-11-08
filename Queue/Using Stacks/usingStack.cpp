#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    stack<int> s1;
    stack<int> s2;
    void enqueue(int value);
    int dequeue();
};

void Queue::enqueue(int value)
{
    s1.push(value);
}

int Queue::dequeue()
{
    if (s1.empty() && s2.empty())
        cout << "Queue is empty" << endl;
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int popped = s2.top();
    s2.pop();
    return popped;
}
int main()
{
    Queue queue;
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    cout << queue.dequeue() << " has been dequeued" << endl;
    cout << queue.dequeue() << " has been dequeued" << endl;
    cout << queue.dequeue() << " has been dequeued" << endl;
    cout << queue.dequeue() << " has been dequeued" << endl;
    cout << queue.dequeue() << " has been dequeued" << endl;
    cout << queue.dequeue() << " has been dequeued" << endl;

    return 0;
}