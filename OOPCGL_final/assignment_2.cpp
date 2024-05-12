#include <iostream>
#include <string.h>
using namespace std;

// static int cnt;

class Student;
class personal
{
    string driving_no;
    public:
    friend class Student;
};

class Student  //generic
{
    string name ,clas, dob, blood_grp, add;
    int rollno, div, phno;
    
    public:
    static int cnt;
    Student()
    {
        personal p;
        // default constructor
        cout<<"default constructor ."<<endl;
        cnt++;
    }

    Student(string namee, string clasS, int Div, int Rollno, int Phno, string dOb, string blood, string aDd, string drivi)
    {
        personal p;
        cout<<"Parameterized Constructor"<<endl;
        name = namee;
        clas = clasS;
        div = Div;
        rollno = Rollno;
        phno = Phno;
        dob = dOb;
        blood_grp = blood;
        add = aDd;
        p.driving_no = drivi;
        cnt++;
        }

    Student (Student &s)
    {
        personal p;
        cout<<"Copy Constructor"<<endl;
        this->name = s.name;
        this->clas = s.clas;
        this->div = s.div;
        this->rollno = s.rollno;
        this->phno = s.phno;
        this->dob = s.dob;
        this->blood_grp = s.blood_grp;
        this->add = s.add;
        cnt++;
    }

    ~Student()
    {
        cout<<"Student Class Destructor."<<endl;
        cnt--;
        getcnt();

    }

    void input(personal &p)
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Class :";
        cin>>clas;
        cout<<"Enter Rollno";
        cin>>rollno;
        cout<<"Enter Division :";
        cin>>div;
        cout<<"Enter Phone Number :";
        cin>>phno;
        cout<<"Enter Date of Birth :";
        cin>>dob;
        cout<<"Enter Address :";
        cin>>add;
        cout<<"drving license :";
        cin.ignore();
		getline(cin, p.driving_no);
        cout<<"------------------"<<endl;
    }

    static inline void getcnt()
{
    cout<<"cnt :"<<cnt<<endl;
}

    void display()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Class :"<<clas<<endl;
        cout<<"Division :"<<div<<endl;
        cout<<"Roll Number :"<<rollno<<endl;
        cout<<"Phone Number :"<<phno<<endl;
        cout<<"Address :"<<add<<endl;
        cout<<"Date of Birth :"<<dob<<endl;
    }



    // inline void getcount()
	// {
	// 	cout<<"count is "<<cnt<<endl;
	// }



};

int Student::cnt = 0;
int main()
{
    personal p;
    int n;
    cout<<"Enter n :";
    cin>>n;
    Student s1[n];
    for(int i = 0; i < n; i++)
    {
        s1[i].input(p); 
    }
    cout<<"--------"<<endl;
    for(int i = 0; i < n; i++)
    {
        s1[i].display(); 
        cout<<"--------"<<endl;
    }

    Student::getcnt();
    delete [] s1;
    Student::getcnt();
    
    return 1;
}


//  dynamic memory alloc using new and delete and exception handling static func inline func