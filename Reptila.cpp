#include "Reptila.h"
#include<iostream>
Reptila::Reptila(): Vertebrat(),temperatura_corp(0)
{

}
Reptila::Reptila(string nume,double lungime,int numar_solzi):
     Vertebrat(nume,lungime), temperatura_corp(temperatura_corp)
{

}
Reptila::Reptila(const Reptila& other)
{
    nume = other.nume;
    lungime = other.lungime;
    temperatura_corp = other.temperatura_corp;
}
Reptila::~Reptila()
{

}
void Reptila::MediuViata() const
{
    cout<<"Reptilele traiesc in mediu predominant terestru.\n";
}
void Reptila::Afis()
{
    Animal::Afis();
    cout<<"Temperatura corp: "<<temperatura_corp<<"\n";


}
istream& operator>>(istream& in,Reptila& ob )
{

    cout<<"Nume: ";
    in>>ob.nume;
    cout<<"Lungime: ";
    in>>ob.lungime;
    cout<<"Temperatura corp: ";
    in>>ob.temperatura_corp;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,Reptila& ob)
{
    ob.Afis();
}
Reptila& Reptila::operator=(const Reptila& ob)
{
   Animal::operator=(ob);
   this->temperatura_corp = temperatura_corp;
   return *this;
}

