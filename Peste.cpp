#include "Peste.h"
#include<iostream>

Peste::Peste():Vertebrat(), numar_solzi(0),tip(-1)
{

}
Peste::Peste(string nume,double lungime,bool tip,int nr_solzi) :
    Vertebrat(nume,lungime),tip(tip),numar_solzi(numar_solzi)
{


}
Peste::Peste(const Peste&other)
{
    nume = other.nume;
    lungime = other.lungime;
    tip = other.tip;
    numar_solzi = other.numar_solzi;
}

Peste::~Peste()
{

}
void Peste::MediuViata() const
{
    cout<<"Pestii traiesc in mediul agvatic.\n";
}
void Peste::Afis()
{
    Animal::Afis();
    if(tip==0)
        cout<<"Nu este peste rapitor; ";
    if(tip ==1)
        cout<<"Este peste rapitor; ";

    cout<<"Numar solzi: "<<numar_solzi<<";\n";


}
istream& operator>>(istream& in,Peste& ob )
{

    cout<<"Nume: ";
    in>>ob.nume;
    cout<<"Lungime: ";
    in>>ob.lungime;
    cout<<"Tip (0-Nu e rapitor, 1-Rapitor): ";
    in>>ob.tip;
    cout<<"Numar solzi: ";
    in>>ob.numar_solzi;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,Peste& ob)
{
    ob.Afis();
}
Peste& Peste::operator=(const Peste& ob)
{
   Animal::operator=(ob);
   this->numar_solzi = numar_solzi;
   this->tip = tip;
   return *this;
}
double Peste::getLungime()
{
    return lungime;
}
bool Peste::getTip()
{
    return tip;
}





