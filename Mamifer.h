#include<Vertebrat.h>
#pragma once

class Mamifer: public Vertebrat
{
protected:
    int numar_pui;
public:
    Mamifer();
    Mamifer(string,double,int);
    Mamifer(const Mamifer&);
    ~Mamifer();
    void MediuViata()const;
    virtual void Afis();

    friend istream& operator>>(istream&,Mamifer& );
    friend ostream& operator<<(ostream&,Mamifer& );

    Mamifer& operator=(const Mamifer&);


};


