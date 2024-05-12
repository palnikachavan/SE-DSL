#include <iostream>
using namespace std;
#define max 20
template <class T>
class ele
{
    public:
    T data;
    int prio;

    bool operator <=(ele obj)
    {
        if (prio <= obj.prio)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class Pqueue
{
    ele <int> pq[max];
    int front;
    int rear;
    public:
    Pqueue()
    {
        front = rear = -1;
    }

    bool QFull()
    {
        if(rear >= max - 1){
            return 1;
        }
        else
            return 0;
    }

    bool QEmpty()
    {
        if(front == -1 || front > rear)
        {
            return 1;
        }
        else
            return 0;
    }

    void enqueue(int data, int p)
    {   
        if(QFull())
        {
            cout<<"Queue Overflow."<<endl;
        }
        else
        {
            ele <int> e1;
            e1.data = data;
            e1.prio = p;

            if(front == -1)
            {
                front = rear = 0;
            }
            int i = 0;
            // finding place for e1
            while (pq[i].prio<= e1.prio && !QEmpty())
            {
                i++;
            }
            // shifting elements
            for(int j = i; j <= rear; j++)
            {
                pq[j + 1] = pq[j];
            }
            rear++;
            pq[rear] = e1;
        }
    }

    int dequeue()
    {
        if (!QEmpty())
        {
            int out;
            out = pq[front].data;
            cout<<"Priority :"<<pq[front].prio<<endl;
            front++;
            return out;
        }
        else
        {
            cout<<"Queue Underflow"<<endl;
        }
    }

    void display()
    {
        if (!QEmpty())
        {
            for(int i = front + 1; i <= rear; i++)
            {
                cout<<"Data :"<<pq[i].data<<endl;
                cout<<"Priority ;"<<pq[i].prio<<endl;
            }
        }
        else
        {
            cout<<"Queue is Empty."<<endl;
        }
    }
};

int main()
{

    int d, p;
    int n;
    Pqueue pq;
    cout<<"Enter Data :";
    cin>>d;
    cout<<"Enter Priority :";
    cin>>p;
        pq.enqueue(d,p);
        cout<<"Enter Data :";
    cin>>d;
    cout<<"Enter Priority :";
    cin>>p;
        pq.enqueue(d,p);
        cout<<"Enter Data :";
    cin>>d;
    cout<<"Enter Priority :";
    cin>>p;
    pq.enqueue(d,p);

    pq.display();

    return 0;
}