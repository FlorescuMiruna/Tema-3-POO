#include "Animal.h"
#include<iostream>

using namespace std;

Animal::Animal()
{

    nume = "";
    lungime = 0;
}
Animal::Animal(string nume,double lungime)
{
    this->nume = nume;
    this->lungime = lungime;

}
Animal::Animal(const Animal&other)
{
    nume = other.nume;
    lungime = other.lungime;
}

Animal::~Animal()
{

}
string Animal::getNume()
{
    return nume;
}
void Animal::Afis()
{
    cout<<"Nume: "<<nume<<"; Lungime:"<<lungime<<"; ";
}
istream& operator>>(istream& in,Animal& ob )
{
    cout<<"Nume: ";
   in>>ob.nume;
   cout<<"Lungime: ";
    in>>ob.lungime;

    return in;
}

ostream& operator<<(ostream& out,Animal& ob)
{

    ob.Afis();

}
Animal& Animal::operator=(const Animal& ob)
{
    this->nume = ob.nume;
    this->lungime = ob.lungime;
    return *this;
}




