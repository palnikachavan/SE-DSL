#include <iostream>
#include <string.h>
using namespace std;

class Publication
{
    public:
    string name;
    float cost;

    Publication()
    {
        name = "";
        cost = 0.0;
    }
};

class Book:public Publication
{
    int page;
    public:
    Book()
    {
        page = 0;
    }
    void input()
    {
        cout<<"Enter Name of Book :";
        cin>>name;
        cout<<"Enter Price of Books :";
        cin>>cost;
        cout<<"Enter Number of Pages :";
        cin>>page;
    }

    void display()
        {
            cout<<"Name :"<<name<<endl;
            cout<<"Number of Pages :"<<page<<endl;
            cout<<"Price :"<<cost<<endl;
        }

};

class Tape:public Publication
{
    float time;
    public:
    Tape()
    {
        time = 0.0;
    }
    void input()
    {
        cout<<"Enter Name of Tape :";
        cin>>name;
        cout<<"Enter Price of Tape :";
        cin>>cost;
        cout<<"Enter Number of Minutes :";
        cin>>time;
    }

    void display()
        {
            cout<<"Name :"<<name<<endl;
            cout<<"Number of Minutes :"<<time<<endl;
            cout<<"Price :"<<cost<<endl;
        }
};

int main()
{
    Book b;
    b.input();
    Tape t;
    t.input();
    b.display();
    t.display();
    return 1;

}

//negative number exception for cost and no of pages/mins