#include<Vertebrat.h>
#pragma once

class Reptila: public Vertebrat
{
protected:
    int temperatura_corp;
public:
    Reptila();
    Reptila(string,double,int);
    Reptila(const Reptila&);
    virtual ~Reptila();
    void MediuViata() const;
    void Afis();

    friend istream& operator>>(istream&,Reptila& );
    friend ostream& operator<<(ostream&,Reptila& );

    Reptila& operator=(const Reptila&);

};


