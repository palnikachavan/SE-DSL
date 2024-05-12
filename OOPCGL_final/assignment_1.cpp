#include <iostream>
using namespace std;


class Complex
{
    int real, imag;
    public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex operator +(Complex c1)
    {
        Complex res;
        res.real = real + c1.real;
        res.imag = imag + c1.imag;
        return res;
    }

    Complex operator -(Complex c1)
    {
        Complex res;
        res.real = real - c1.real;
        res.imag = imag - c1.imag;
        return res;
    }

    Complex operator *(Complex c1)
    {
        Complex res;
        res.real = (real * c1.real) - (imag * c1.imag);
        res.imag = (real * c1.imag) + (imag * c1.real);
        return res;
    }
    friend ostream &operator <<(ostream &out, Complex &c1);
    friend istream &operator >>(istream &in, Complex &c1);
};
ostream &operator <<(ostream &out, Complex &c1)
{
    if (c1.imag >= 0)
    {
        out<<c1.real<<'+'<<c1.imag<<'i'<<endl;
    }
    else
    {
        out<<c1.real<<c1.imag<<'i'<<endl;
    }
    return out;
}

istream &operator >>(istream &in, Complex &c1)
{
    cout<<"Enter Real part :"<<endl;
    in>>c1.real;
    cout<<"Enter Imaginary part :"<<endl;
    in>>c1.imag;
    return in;
}





int main()
{
    Complex c1, c2, c3;
    cin>>c1;    
    cin>>c2;
    c3 = c1 * c2;
    cout<<c3;
}


//ostream & operator <<(ostream &out, Compelx &x)
//istream &operator >>(istream &in, Complex &q)