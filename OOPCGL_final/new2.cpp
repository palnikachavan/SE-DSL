#include <iostream>
using namespace std;

class Personal
{
private:
	string bldgrp,dob,addr;
	int contact;
public:
	friend class Student;
};

class Student		//generic
{
private:
	string name,std;
	int rollno, div;
public:

	static int cnt;


	Student()
	{
		Personal p;
		name = "";
		std = "";
		div = 0;
		rollno = 0;
		p.contact = 0;
		p.bldgrp = "";
		p.dob = "";
		Student::cnt++;

	};


	Student(string name1, string std1, int div1, int rollno1, int contact, string bldgrp, string dob)
	{
		Student temp;
		Personal p;
		name = name1;
		std = std1;
		div = div1;
		rollno = rollno1;
		p.contact = contact;
		p.bldgrp = bldgrp;
		p.dob = dob;
	};


	Student(Student &s,Personal &p)
	{

		this -> name = s.name;
		this-> std = s.std;
		this-> div = s.div;
		this-> rollno = s.rollno;

	}



	~Student()
	{
		Student::cnt--;
		cout<<"Destructor"<<endl;
	}



	static inline void getcount()
	{
		cout<<"count is "<<cnt<<endl;
	}





	void getinput(Personal &p)
	{

		cout<<"Enter student name: ";
		cin>>name;
		cout<<"Enter class of student(FE/SE/TE/BE): ";
		cin>>std;
		cout<<"Enter the division of student: ";
		cin>>div;
		cout<<"Enter the roll no. of student: ";
		cin>>rollno;
		cout<<"Enter the contact no. of student: ";
		cin>>p.contact;
		cout<<"Enter the blood group of student: ";
		cin>>p.bldgrp;
		cout<<"Enter the date of birth of student(DD/MM/YYYY): ";
		cin>>p.dob;
		cout<<"Enter the address of Student: ";
		cin.ignore();
		getline(cin, p.addr);
	};

	void showinput(Personal &p)
	{
		cout<<"-----------------------------------------"<<endl;
		cout<<"Name of student is: "<<name<<endl;
		cout<<"Student is studying in: "<<std<<"-"<<div<<endl;
		cout<<"Roll no. of student is:"<<rollno<<endl;
		cout<<"Contact number of student is: "<<p.contact<<endl;
		cout<<"Blood group of student is: "<<p.bldgrp<<endl;
		cout<<"Date of Birth of student is: "<<p.dob<<endl;
		cout<<"Address of student is: "<<p.addr<<endl;
		cout<<"-----------------------------------------"<<endl;
	}
};

int Student::cnt = 0;


int main() {
	int n;
	cout<<"Enter the no. of students: "<<endl;
	cin>>n;
	Student *s;
	Personal p;
	s = new Student[n];
	for(int i=0; i<n; i++)
	{
		s[i].getinput(p);
		s[i].showinput(p);
	};
	Student::getcount();
    s[0].showinput(p);
	delete[] s;
	Student::getcount();
	return 0;
}
