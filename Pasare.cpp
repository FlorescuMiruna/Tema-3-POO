#include "Pasare.h"
#include<iostream>


Pasare::Pasare():Vertebrat(),numar_pene(0),numar_oua_luna(0)
{

}
Pasare::Pasare(string nume,double lungime,int nr_pene):
    Vertebrat(nume,lungime),numar_pene(numar_pene),numar_oua_luna(numar_oua_luna)
{

}
Pasare::Pasare(const Pasare& other)
{
    nume = other.nume;
    lungime = other.lungime;
    numar_pene = other.numar_pene;
}
Pasare::~Pasare()
{
}
Pasare::calculeazaNrOuaAn()
{
    return numar_oua_luna*12;
}
void Pasare::MediuViata() const
{
    cout<<"Pasarile traiesc predominant in mediul aerian.\n";
}
void Pasare::Afis()
{
    Animal::Afis();
    cout<<"Numar pene: "<<numar_pene<<";\n";

}

istream& operator>>(istream& in,Pasare& ob )
{

    cout<<"Nume: ";
    in>>ob.nume;
    cout<<"Lungime: ";
    in>>ob.lungime;
    cout<<"Numar pene: ";
    in>>ob.numar_pene;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,Pasare& ob)
{

    ob.Afis();
}
Pasare& Pasare::operator=(const Pasare& ob)
{
   Animal::operator=(ob);
   this->numar_pene= numar_pene;
   return *this;
}

