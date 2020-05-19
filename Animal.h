#include<string>
#pragma once

using namespace std;
class Animal
{
public:
    string nume;
    double lungime;
public:
    Animal();
    Animal(string, double);
    Animal(const Animal&);
    virtual ~Animal();
    virtual void MediuViata() const = 0 ;
    string getNume();
    virtual void Afis() = 0;
    friend istream& operator>>(istream&,Animal& );
    friend ostream& operator<<(ostream&,Animal& );

	Animal& operator=(const Animal&);


};

