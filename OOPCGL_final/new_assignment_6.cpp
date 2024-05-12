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
        cost = 100;
        qty = 1;
        name = "ABCDE";
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
    return i1.itcd < i2.itcd;
}

bool sort_by_cost(Item i1, Item i2)
{
    return i1.cost < i2.cost;
}

int main()
{
    vector <Item> items;
    Item i1;
    int n, i;
    cout<<"Enter Nummber of Entries to make :";
    cin>>n;
    for(i = 0; i < n;i++)
    {
        i1.input();
        items.push_back(i1);
        cout<<"--------------------"<<endl;
    }

    cout<<"Displaying.. "<<endl;
    vector <Item> ::iterator itr, it1, it2;
    itr = items.begin();

    while (itr != items.end())
    {
        itr->display();
        itr++;
        cout<<"--------------------"<<endl;
    }
    
    // sort(items.begin(), items.end(), sort_by_itmcd);
    // itr = items.begin();
    // while (itr != items.end())
    // {
    //     itr->display();
    //     itr++;
    //     cout<<"--------------------"<<endl;
    // }
    string Name;
    cout << "Enter Item Name to search :";
    cin >> Name;
    Item i2(0, Name, 0, 0);
    itr = find(items.begin(), items.end(), i2);
    if (itr != items.end())
        itr->display();
    else
        cout << "Not Found."<<endl;
    return 1;
}


// search me --> make a temporary obj of class with only 1 entry filled and search that in vector using find() method