#include "Mamifer.h"
#include<iostream>

Mamifer::Mamifer() : Vertebrat(),numar_pui(0)
{

}

Mamifer::Mamifer(string nume,double lungime,int nr_pui) :
    Vertebrat(nume,lungime),numar_pui(numar_pui)
{

}
Mamifer::Mamifer(const Mamifer&other)
{
    nume = other.nume;
    lungime = other.lungime;
    numar_pui = other.numar_pui;
}

Mamifer::~Mamifer()
{

}

void Mamifer::MediuViata() const
{
    cout<<"Mamiferele traiesc predominant in mediul terestru.\n";
}
void Mamifer::Afis()
{
    Animal::Afis();
    cout<<"Numar pui: "<<numar_pui<<";\n";

}
istream& operator>>(istream& in,Mamifer& ob )
{

    cout<<"Nume: ";
    in>>ob.nume;
    cout<<"Lungime: ";
    in>>ob.lungime;
    cout<<"Numar pui: ";
    in>>ob.numar_pui;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,Mamifer& ob)
{
    ob.Afis();
}
Mamifer& Mamifer::operator=(const Mamifer& ob)
{
   Animal::operator=(ob);
   this->numar_pui = numar_pui;
   return *this;
}
