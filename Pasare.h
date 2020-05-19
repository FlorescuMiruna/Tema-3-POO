#include<Vertebrat.h>
#pragma once

class Pasare: public Vertebrat
{
protected:
    int numar_pene;
    int numar_oua_luna;
public:
    Pasare();
    Pasare(string,double,int);
    Pasare(const Pasare&);
    ~Pasare();
    void MediuViata() const;
    void Afis();
    int calculeazaNrOuaAn();

    friend istream& operator>>(istream&,Pasare& );
    friend ostream& operator<<(ostream&,Pasare& );

    Pasare& operator=(const Pasare&);



};


