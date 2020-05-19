#include<Vertebrat.h>
#pragma once

class Peste:public Vertebrat
{

protected:
    bool tip; ///0-nerapitor, 1-rapitor
    int numar_solzi;

public:
    Peste();
    Peste(string,double,bool,int);
    Peste (const Peste&);
    ~Peste();
    void MediuViata() const;
    void Afis();


    friend istream& operator>>(istream&,Peste& );
    friend ostream& operator<<(ostream&,Peste& );

    Peste& operator=(const Peste&);

    double getLungime();
    bool getTip();


};


