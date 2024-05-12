#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next, *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLList
{
    friend class Node;
    Node *head;
    public:
    DLList()
    {
        head = NULL;
    }

    void insert_first(int d)
    {
        Node *temp = new Node(d);
        if(head == NULL)
        {
            head = temp;
            temp->next = temp;
            temp->prev = temp;
        }
        else
        { 
            head->prev->next = temp;
            temp->prev = head->prev;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insert_last(int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = temp;
            temp->next = temp;
            temp->prev = temp;
        }
        else 
        {
            Node *nptr;
            nptr = head->next;
            while (nptr->next != head)
                nptr = nptr->next;
            nptr->next = temp;
            temp->prev = nptr;
            temp->next = head;
            head->prev = temp;
        }
    }

    void display()
    {
        Node *nptr;
        nptr = head->next;
        cout<<head->data<<"--";
        while (nptr != head)
        {
            cout<<nptr->data<<"--";
            nptr = nptr->next;
        }
        cout<<endl;
        // cout<<nptr->next->data<<endl;
    }

    void binary(int d)
    {
        while (d > 0)
        {
            int temp = 0;
            temp = d % 2;
            insert_first(temp);
            d = d / 2;
        }
    }
    DLList complement1s()
    {
        Node *temp;
        DLList res;
        temp = head->next;
        if(head->data == 1)
        {
            res.insert_last(0);
        }
        else
        {
            res.insert_last(1);
        }
        while(temp != head)
        {
            if(temp->data == 1)
            {
                res.insert_last(0);
            }
            else
            {
                res.insert_last(1);
            }
            temp = temp->next;
        }

        return res;
    }

    // DLList complement2s()
    // {
    //     DLList l1,l2;
    //     int temp;
    //     l1 = complement1s();
    //     int carry = 1;
    //     Node *nptr;
    //     nptr = l1.head->next;
    //     while(nptr->next != l1.head)
    //     {
    //         nptr = nptr->next;
    //     }
    //     while(nptr != l1.head)
    //     {
    //         temp = nptr->data;
    //         if (temp == 1 && carry == 1)
    //         {
    //             temp = 0;
    //             carry = 1;
    //         }
    //         else if(temp == 0 && carry == 1)
    //         {
    //             temp = 1;
    //             carry = 0;
    //         }
    //         else
    //         {
    //             insert_first(nptr->data);
    //         }
    //         l2.insert_first(temp);
    //         nptr = nptr->prev;
    //     }
    //     l2.insert_first(nptr->data);
    //     if (carry == 1)
    //     {
    //         l2.insert_first(carry);
    //     }
    //     l2.display();
    //     return l2;
    // }

    DLList complement2s()
    {
        DLList dll, dlres;
        dll = complement1s();
        int carry = 1, temp;
        Node *nptr;
        nptr = dll.head->prev;
        temp = dll.head->prev->data;
        while(nptr != dll.head)
        {
            if (temp == 1 && carry == 1)
            {
                temp = 0;
                carry = 1;
            }
            else if(temp == 0 && carry == 1)
            {
                temp = 1;
                carry = 0;
            }
            dlres.insert_first(temp);
            nptr = nptr->prev;
            temp = nptr->data;
        }
        dlres.insert_first(nptr->data);
        dlres.display();
        return dlres;
    }

    int deci()
    {
        int i = 0, res = 0;
        Node *np = head->prev;
        while(np->prev != head)
        {
            res += np->data * (pow(2, i)); 
            np = np->prev;
            i++;
        }
        res += np->data * (pow(2, i));
        res += np->prev->data * (pow(2, i+1));
        return res;
    }
    
};
DLList operator +(DLList l, DLList l2)
{
    int x, y;
    x = l2.deci();
    y = l.deci();
    DLList res;
    int out;
    out = x + y;
    res.binary(out);
    return res;
}



int main()
{
    DLList l,l1, res;
    int x;
    l.binary(10);
    l1.binary(5);
    res = l + l1;
    res.display();
    // l1 = l.complement2s();
    // x = l.deci();
    // cout<<"result :"<<x<<endl;
    return 1;
}