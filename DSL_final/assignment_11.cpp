#include <iostream>
#include <string.h>
using namespace std;

class Queue
{
    int Q[20];
    int front, rear;
    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int d)
    {
        if (front == 0 && rear == 19)
        {
            cout<<"Queue Overflow."<<endl;
        }
        else if(front == -1)
        {
            front = 0;
            rear = 0;
            Q[rear] = d;
        }
        else
        {
            rear ++;
            Q[rear] = d;
        }
    }

    void display()
    {
        int i;
        for(i = front; i <= rear; i ++)
        {
            cout<<Q[i]<<"~";
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout<<"Queue Underflow."<<endl;
        }
        else if(front == rear)
        {
            int out;
            out = Q[front];
            front = -1;
            rear = -1;
            return out;
        }
        else
        {
            int out;
            out = Q[front];
            front++;
            return out;
        }
        return 0;
    }
};

int main()
{
    Queue q1;
    int x;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(50);
    q1.display();
    cout<<endl;
    x = q1.dequeue();
    cout<<"Result :"<<x<<endl;
    cout<<endl;
    q1.display();
    return 1;
}