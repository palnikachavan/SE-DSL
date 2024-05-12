#include <iostream>
using namespace std;

class SLList;
class Node
{   
    friend class SLList;
    int data;
    Node *next;
    public:
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class SLList
{
    Node *head, *tail;
    public:
    SLList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_first(int d)
    {
        Node *temp = new Node(d);
        if(head == NULL)
        {
            temp->next = head;
            head = temp;
            tail = temp;
        }

        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void insert_last(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            temp->next = head;
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display()
    {
        Node * npt = head;
        cout<<head->data<<"--";
        while(npt->next != NULL)
        {
            npt = npt->next;
            cout<<npt->data<<"--";
        }
    }

    SLList Union(SLList l1)
    {
        SLList res;
        res = l1;
        Node *npt = head;
        Node *npt1 = res.head;
        bool flag = 0;
        while(npt->next != NULL)
        {
            while(npt1->next != NULL)
            {
                if (npt->data != npt1->data)
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
                npt1 = npt1->next;
            }
            if (flag == 1)
            {
                res.insert_last(npt->data);
                flag = 0;
            }
            npt = npt->next;
        }
        npt1 = res.head;
        while(npt1->next != NULL)
            {
                if (npt->data != npt1->data)
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
                npt1 = npt1->next;
            }
            if (flag == 1)
            {
                res.insert_last(npt->data);
            }
        return res;
    }
};

int main()
{
    SLList s;
    SLList s1, res;
    s.insert_first(10);
    s.insert_first(20);
    s.insert_last(8);
    s1.insert_last(1);
    s1.insert_last(2);
    s1.insert_last(8);
    s1.insert_last(30);
    cout<<"-----------------"<<endl;
    s.display();
    cout<<"******************"<<endl;
    s1.display();
    res = s1.Union(s);
    cout<<"/////////////////"<<endl;
    res.display();
    return 0;
}