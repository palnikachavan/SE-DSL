#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
    int itcd, cost, qty;
    string name;

    public:
    Item()
    {
        itcd = 0;
        cost = 0;
        qty = 0;
        name = "";
    }

    Item(int i, string n, int c, int q)
	{
    	itcd = i;
		name = n;
		cost = c;
		qty = q;
	}

    void input()
    {
        cout<<"Enter Item Name :";
        cin>>name;
        cout<<"Enter Item Code :";
        cin>>itcd;
        cout<<"Enter Quantity :";
        cin>>qty;
        cout<<"Enter per Item Cost :";
        cin>>cost;
    }

    void display()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Item Code :"<<itcd<<endl;
        cout<<"Quantity :"<<qty<<endl;
        cout<<"Cost :"<<cost<<endl;
    }

    friend bool sort_by_itmcd(Item i1, Item i2);
    friend bool sort_by_cost(Item i1, Item i2);


};

bool sort_by_itmcd(Item i1, Item i2)
{
    return i1.itcd <= i2.itcd;
}

bool sort_by_cost(Item i1, Item i2)
{
    return i1.cost <= i2.cost;
}

int main()
{
    vector <Item> items;
    vector <Item> ::iterator itr;
    Item i1;
    char s;
    int itc;
    int x;
    int n, i, o;
    char ch = 'y';
    string st;
while(ch == 'y'){
    cout<<"\t\tMENU"<<endl;
    cout<<"1. Enter Data."<<endl;
    cout<<"2. Display Data."<<endl;
    cout<<"3. Sort Data"<<endl;
    cout<<"4. Search Data."<<endl;
    cin>>o;
    switch (o)
    {
    case 1:
    {
        cout<<"Enter Nummber of Entries to make :";
        cin>>n;
        for(i = 0; i < n;i++)
        {
            i1.input();
            items.push_back(i1);
            cout<<"--------------------"<<endl;
        }
        break;
    }
    case 2:
    {
        cout<<"Displaying.. "<<endl;
        itr = items.begin();
        while (itr != items.end())
        {
            itr->display();
            itr++;
            cout<<"--------------------"<<endl;
        }
        break;
    }
    case 3:
    {
        cout<<"1. Sort by Item Code."<<endl;
        cout<<"2. Sort by Item Cost."<<endl;
        cin>>x;
        switch (x)
        {
        case 1:
        {
            sort(items.begin(), items.end(), sort_by_itmcd);
            itr = items.begin();
            while (itr != items.end())
            {
                itr->display();
                itr++;
                cout<<"--------------------"<<endl;
            }
            break;
        }
        case 2:
        {
            sort(items.begin(), items.end(), sort_by_cost);
            itr = items.begin();
            while (itr != items.end())
            {
                itr->display();
                itr++;
                cout<<"--------------------"<<endl;
            }
        }
        default:
            break;
        }
    
    }
    // case 4:
    // {

    //     cout<<"a. Search by Item Name"<<endl;
    //     cout<<"b. Search by Item Code."<<endl;
    //     cin>>s;
    //     switch (s)
    //     {
    //     case 'a':
    //         cout<<"Enter Name :";
    //         cin>>st;
    //         Item temp1(0,st,0,0);
    //         itr = find(items.begin(),items.end(),temp1);
    //         if(itr != items.end())
    //         {
    //             cout<<"Item found."<<endl;
    //             itr->display();
    //         }
    //         else
    //         {
    //             cout<<"Item NOT found."<<endl;
    //         }
    //         break;
    //     }
    //     case 'b':
    //     {
    //         cout<<"Enter Item Code :";
    //         cin>>itc;
    //         Item temp(itc,"",0,0);
    //         itr = find(items.begin(),items.end(),temp);
    //         if(itr != items.end())
    //         {
    //             cout<<"Item found."<<endl;
    //             itr->display();
    //         }
    //         else
    //         {
    //             cout<<"Item NOT found."<<endl;
    //         }
    //         break;
    //     }
        
    // }
    default:
        break;

    }
}
    return 1;
}


// search me --> make a temporary obj of class with only 1 entry filled and search that in vector using find() method