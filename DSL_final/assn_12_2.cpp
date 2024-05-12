// Write program to implement a priority queue in C++ using
// an order list/array to store the items in the queue. Create a
// class that includes the data items (which should be template)
// and the priority (which should be int). The order list/array
// should contain these objects, with operator <= overloaded so
// that the items with highest priority appear at the beginning of
// the list/array (which will make it relatively easy to retrieve the
// highest item.)

#include <iostream>
// #include <vector>
using namespace std;

#define MAX 30

template <class T>
class Element
{
    public:
    T item;
    int priority;

    bool operator <= (Element& obj)
    {
        if (priority <= obj.priority)
            return 1;
        else
            return 0;
    }
};

class PQueue
{
    Element<string> PQue[MAX];
    int front;
    int rear;

    public:
    PQueue()
    {
        front = rear = -1;
    }

    int QFull()
    {
        if(rear >= MAX - 1){
            return 1;
        }
        else
            return 0;
    }

    int QEmpty()
    {
        if(front == -1 || front > rear){
            return 1;
        }
        else
            return 0;
    }

    void add(string s, int p)
    {
        if (QFull())
            return;
        
        Element<string> ele;
        ele.item = s;
        ele.priority = p;


        if(front == -1)
            front++;

        int i = 0;
        while(PQue[i].priority <= ele.priority && !QEmpty())
        {
            i++;
        }

        for (int j = i; j <= rear; j++)
        {
            PQue[j+1] = PQue[j];
        }

        rear++;
        PQue[i] = ele; 
    }

    void del()
    {
        if(!QEmpty())
        {
            front++;
        }
        else
        {
            cout<<"PQueue is empty"<<endl;
        }
    }
    
    void display()
    {
        if(!QEmpty())
        {
            for(int i = front; i != rear+1 ; i++ )
            {
                cout << PQue[i].priority << ". " <<PQue[i].item << endl;
            }
        }
        else
        {
            cout<<"Queue is empty"<<endl;
        }
    }

};

int main()
{
    int op;
    string item;
    int p;

    PQueue Q;

    do{
        cout<< "1.add, 2.display, 3.delete choose:"<<endl;
        cin>>op;

        switch (op)
        {
        case 1:
            
            cout<<"Enter item1"<<endl;
            cin>>item;

            cout<<"Enter priority"<<endl;
            cin>>p;

            Q.add(item,p);
            break;

        case 2:
            Q.display();
            break;

        case 3:
            Q.del();
            break;
        
        default:
            break;
        }

    }while(op!=0);
    return 0;
}