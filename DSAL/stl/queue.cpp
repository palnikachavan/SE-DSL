#include <iostream>
using namespace std;

template<typename T>
class Queue
{
    int back, front;
    T queue[50];

    public:
    Queue()
    {
        back = front = -1;
    }
    void push(T x)
    {
        if(back == 49)
        {
            return;
        }
        else if(front == -1 && back == -1)
        {
            front = 0;
            back = 0;
            queue[back] = x;
            return;
        }
        back ++;
        queue[back] = x;
    }

    void pop()
    {
        if(front = 0)
        {
            return;
        }
        else if (front == back)
        {
            front = back = -1;
            return;
        }
        front++;
    }

    bool empty()
    {
        if(front == -1)
            return 1;
        else
            return 0;
    }

    T top()
    {

        return queue[front];
    }
};

int main()
{
    Queue<int> q;
    q.push(100);
    q.push(200);
    q.push(20);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    cout<<q.empty()<<endl;
}