#include <bits/stdc++.h>
using namespace std;
#define MAX 10
class Queue
{
public:
    int front, back;
    int arr[MAX];
    Queue() { front = -1, back = -1; }
    int isEmpty();
    int isFull();
    void enqueue(int value);
    void dequeue();
    void peek();
};
int Queue::isEmpty()
{
    if (front < 0)
        return 1; // return 1 if it is empty

    else
        return 0;
}
int Queue::isFull()
{
    if (front == 0 && back >= MAX - 1)
        return 1; // return 1 if it is full
    else
        return 0;
}

void Queue::enqueue(int value)
{
    if (isFull())
        cout << "stack overflow" << endl;

    else
    {
        if (front == -1)
        {
            arr[++back] = value;
            ++front;
        }
        else
            arr[++back] = value;

        cout << value << " enqueued" << endl;
    }
}

void Queue::dequeue()
{
    if (isEmpty())
        cout << "stack underflow" << endl;

    else
    {
        int x = arr[front];
        if (front >= back)
        {
            front = -1;
            back = -1;
        }
        else
            front++;
        cout << x << " dequeued" << endl;
    }
}

void Queue::peek()
{
    if (!isEmpty())
        cout << arr[front] << " is in front " << endl;
    else
        cout << "queue is empty" << endl;
}

int main()
{
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    (queue.isFull()) ? cout << "Queue is full" << endl : cout << "Queue is not full" << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.peek();

    return 0;
}