#include <iostream>
#include<fstream>
#include<Animal.h>
#include<Vertebrat.h>
#include<Peste.h>
#include<Pasare.h>
#include<Mamifer.h>
#include<Reptila.h>
#include<list>
#include<vector>
#include<typeinfo>
#include<Exceptie.h>
using namespace std;

template <typename T>
class AtlasZoologic
{
    T* animale;
    int nr;
public:
    static int nr_animale;
    AtlasZoologic()
    {

        animale = new T[100];

    }
    AtlasZoologic(int nr,T*animale)
    {
        animale = new T[100];
        this->nr = nr;
        for(int i=0; i<nr; i++)
            this->animale[i] = animale[i];
    }
    AtlasZoologic(const  AtlasZoologic &other)
    {
        nr = other.nr;
        animale = new T[100];
        for(int i=0; i<nr; i++)
            animale[i] = other.animale[i];
    }
    ~AtlasZoologic()
    {
        delete []animale;
    }
    virtual void Afis()
    {
        cout<<"animale:\n";
        for(int i=0; i<nr; i++)
            cout<<animale[i]<<"\n";
    }
    friend istream& operator>>(istream&, AtlasZoologic<T>&);
    friend ostream& operator<<(ostream&, AtlasZoologic<T>&);


};


istream& operator>>(istream& in, AtlasZoologic<Mamifer>& ob)
{

    cout<<"Cate mamifere doriti sa introduceti? ";
    in>>ob.nr;
    AtlasZoologic<Mamifer>::nr_animale += ob.nr;
    cout<<"Introduceti mamiferele.\n";
    for(int i=0; i<ob.nr; i++)
    {
        cin>>ob.animale[i];
    }

    return in;
}
istream& operator>>(istream& in, AtlasZoologic<Pasare>& ob)
{
    cout<<"Cate pasari doriti sa introduceti? ";
    in>>ob.nr;
    AtlasZoologic<Pasare>::nr_animale += ob.nr;
    cout<<"Introduceti pasarile.\n";
    for(int i=0; i<ob.nr; i++)
        cin>>ob.animale[i];
    return in;
}


istream& operator>>(istream& in, AtlasZoologic<Reptila>& ob)

{
    cout<<"Cate reptile doriti sa introduceti? ";
    in>>ob.nr;
    AtlasZoologic<Reptila>::nr_animale += ob.nr;
    cout<<"Introduceti reptilele.\n";
    for(int i=0; i<ob.nr; i++)
        cin>>ob.animale[i];
    return in;
}
ostream& operator<<(ostream& out, AtlasZoologic<Mamifer>&ob)
{

    for(int i=0; i<ob.nr; i++)
        cout<<ob.animale[i];
    return out;

}

ostream& operator<<(ostream& out, AtlasZoologic<Pasare>&ob)
{


    for(int i=0; i<ob.nr; i++)
        cout<<ob.animale[i];
    return out;

}


ostream& operator<<(ostream& out, AtlasZoologic<Reptila>&ob)
{

    for(int i=0; i<ob.nr; i++)
        cout<<ob.animale[i];
    return out;


}


template <>
class AtlasZoologic<Peste>
{
    Peste* animale;
    int nr;
public:
    static int nr_animale;
    AtlasZoologic()
    {
        animale = new Peste[100];
    }
    AtlasZoologic(int nr,Peste*animale)
    {
        animale = new Peste[100];
        this->nr = nr;
        for(int i=0; i<nr; i++)
            this->animale[i] = animale[i];
    }
    AtlasZoologic(const  AtlasZoologic &other)
    {
        nr = other.nr;
        animale = new Peste[100];
        for(int i=0; i<nr; i++)
            animale[i] = other.animale[i];
    }
    ~AtlasZoologic()
    {
        delete []animale;
    }

    void pestiRapitori()
    {
        int  numar = 0;
        for(int i=0; i<nr; i++)
            if(animale[i].getTip() == 1 && animale[i].getLungime() > 1)
                numar++;
        cout<<"Sunt rapitori si au lungimea mai mare de un metru "<<numar<<" pesti.\n\n";
    }
    friend istream& operator>>(istream&, AtlasZoologic<Peste>&);
    friend ostream& operator<<(ostream&, AtlasZoologic<Peste>&);

};

istream& operator>>(istream& in, AtlasZoologic<Peste>& ob)

{

    cout<<"Cati pesti doriti sa introduceti? ";
    in>>ob.nr;
    AtlasZoologic<Peste>::nr_animale += ob.nr;
    cout<<"Introduceti pestii.\n";
    for(int i=0; i<ob.nr; i++)
        cin>>ob.animale[i];
    return in;
}

ostream& operator<<(ostream& out, AtlasZoologic<Peste>&ob)
{

    for(int i=0; i<ob.nr; i++)
        cout<<ob.animale[i];
    return out;

}

template<typename T>
int AtlasZoologic<T>::nr_animale=0;
int AtlasZoologic<Peste>::nr_animale=0;
int n,tip,operatie;
void AfisMeniu()
{
    cout<<"MENU\n";
    cout<<"1.Introduceti animale in lista.\n";
    cout<<"2.Afisati animalele din lista.\n";
    cout<<"3.Introduceti animale in Atlasul Zoologic.\n";
    cout<<"4.Afisati animalele din Atlasul Zoologic.\n";
    cout<<"5.Afisati numarul animalelor.\n";
    cout<<"6.EXIT\n";
}
int main()
{
    list<Animal*>animale;
    list<AtlasZoologic<Peste>*>pesti;
    list<AtlasZoologic<Mamifer>*>mamifere;
    list<AtlasZoologic<Reptila>*>reptile;
    list<AtlasZoologic<Pasare>*>pasari;

    Mamifer mamifer_1;
    cin>>mamifer_1;
    Mamifer mamifer_2 = mamifer_1; ///operator ==
    Mamifer mamifer_3(mamifer_1); ///CC
    cout<<mamifer_1<<mamifer_2<<mamifer_3<<"\n";

    do
    {
        AfisMeniu();
        cin>>operatie;
        if(operatie == 1)
        {
            cout<<"Numar animale: ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                cout<<"Introduceti tipul animalului:(1-mamifer, 2-pasare, 3-peste, 4-reptila): ";
                cin>>tip;
                if(tip == 1)
                {
                    Mamifer *temp;
                    temp = new Mamifer;
                    cin>>*temp;
                    animale.push_back(temp);


                }

                if(tip == 2)
                {
                    Pasare *temp = new Pasare;
                    cin>>*temp;
                    animale.push_back(temp);
                }
                if(tip == 3)
                {
                    Peste *temp = new Peste;
                    cin>>*temp;
                    animale.push_back(temp);
                }
                if(tip == 4)
                {
                    Reptila *temp = new Reptila;
                    cin>>*temp;
                    animale.push_back(temp);
                }
            }
        }
        if(operatie == 2)
        {


            list<Animal*>::iterator i;
            if(animale.size() == 0)
            {
                try
                {
                    throw(Exceptie("Nu avem animale in lista."));
                }
                catch (exception& e)
                {
                    cout << e.what() << "\n";
                }
            }

            for(i = animale.begin(); i != animale.end(); i++)
            {
                if(typeid(**i)==typeid(Mamifer))

                {
                    Mamifer *temp = dynamic_cast<Mamifer*>(*i);
                    temp->MediuViata();
                    cout<<*temp<<"\n";
                }

                if(typeid(**i)==typeid(Pasare))

                {
                    Pasare *temp = dynamic_cast<Pasare*>(*i);
                    temp->MediuViata();
                    cout<<*temp<<"\n";
                }

                if(typeid(**i)==typeid(Peste))

                {
                    Peste *temp = dynamic_cast<Peste*>(*i);
                    temp->MediuViata();
                    cout<<*temp<<"\n";
                }

                if(typeid(**i)==typeid(Reptila))

                {
                    Reptila *temp = dynamic_cast<Reptila*>(*i);
                    temp->MediuViata();
                    cout<<*temp<<"\n";
                }
            }
        }



        if(operatie == 3)
        {


            cout<<"Numarul de adaugari in Atlasul Zoologic: ";
            cin>>n;
            for(int i=0; i<n; i++)
            {

                cout<<"Tipul(1-mamifer, 2-pasare, 3-peste, 4-reptila): ";
                cin>>tip;
                if(tip == 1)
                {
                    AtlasZoologic<Mamifer>* temp = new  AtlasZoologic<Mamifer>;
                    cin >> *temp;
                    mamifere.push_back(temp);

                }
                if(tip == 2)
                {
                    AtlasZoologic<Pasare>* temp = new  AtlasZoologic<Pasare>;
                    std::cin >> *temp;
                    pasari.push_back(temp);

                }
                if(tip == 3)
                {
                    AtlasZoologic<Peste>* temp = new  AtlasZoologic<Peste>;
                    std::cin >> *temp;
                    pesti.push_back(temp);

                }
                if(tip == 4)
                {
                    AtlasZoologic<Reptila>* temp = new  AtlasZoologic<Reptila>;
                    std::cin >> *temp;
                    reptile.push_back(temp);

                }
            }
        }
        if(operatie == 4)
        {
            if(mamifere.size())
            {

                cout<<"Lista de animale din regnul Mamifer:\n";
                list<AtlasZoologic<Mamifer>*>::iterator m;
                for(m = mamifere.begin(); m != mamifere.end(); m++)
                {

                    cout<<**m;

                }
            }
            else
                cout<<"Nu avem mamifere in atlas.\n\n";
            if(pasari.size())
            {


                cout<<"Lista de animale din regnul Pasare:\n";
                list<AtlasZoologic<Pasare>*>::iterator p;

                for(p = pasari.begin(); p != pasari.end(); p++)
                {

                    cout<<**p;
                }
            }
            else
                cout<<"Nu avem pasari in atlas.\n\n";
            if(pesti.size())

            {

                cout<<"Lista de animale din regnul Peste:\n";
                list<AtlasZoologic<Peste>*>::iterator s;
                for(s = pesti.begin(); s != pesti.end(); s++)
                {

                    cout<<**s;
                    (**s).pestiRapitori();
                }
            }
            else
                cout<<"Nu avem pesti in atlas.\n\n";
            if(reptile.size() != 0)
            {
                cout<<"Lista de animale din regnul Reptila:\n";
                list<AtlasZoologic<Reptila>*>::iterator r;
                for(r = reptile.begin(); r != reptile.end(); r++)
                {

                    cout<<**r;

                }
            }
            else
                cout<<"Nu avem reptile in atlas.\n\n";
        }


        if(operatie == 5)
        {

            cout<<"Numar mamifere: "<<AtlasZoologic<Mamifer>::nr_animale<<"\n";
            cout<<"Numar pasari: "<<AtlasZoologic<Pasare>::nr_animale<<"\n";
            cout<<"Numar pesti: "<<AtlasZoologic<Peste>::nr_animale<<"\n";
            cout<<"Numar reptile: "<<AtlasZoologic<Reptila>::nr_animale<<"\n";

        }
        if(operatie == 6)
            break;
    }
    while(true);



    return 0;
}

