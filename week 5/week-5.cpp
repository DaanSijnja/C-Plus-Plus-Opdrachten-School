// Naam: Daan Sijnja Studentnummer: 20177747
#include <iostream>
using namespace std;

class Vorm{
    public:
        virtual int oppervlakte() const = 0; 
};


class Rechthoek: public Vorm {
    protected:
        int lengte;
        int breedte;
        int grootste(int a, int b) const;
        void normalizeer();
        
    public:
        Rechthoek(int _lengte, int _breedte);
        void drukaf() const;
        void viervoud();
        virtual int oppervlakte() const;
        Rechthoek omvattend(Rechthoek r) const;
};

int Rechthoek::grootste(int a, int b) const {
    if(a > b){ return a; } else { return b; }
}

void Rechthoek::normalizeer()  {
    int zijde0 = lengte;
    int zijde1 = breedte;
    
    if(zijde0 > zijde1){
        lengte = zijde0;
        breedte = zijde1;
    }
    else
    {
        lengte = zijde1;
        breedte = zijde0;
    }
}

Rechthoek::Rechthoek(int zijde0, int zijde1){
    lengte = zijde0;
    breedte = zijde1;
    normalizeer();
}

void Rechthoek::drukaf() const {
    int opp = oppervlakte();
    cout << "Lengte: " << lengte << " Breedte: " << breedte << " Oppervlakte: " << opp << endl;
}

void Rechthoek::viervoud(){
    lengte *= 2;
    breedte *= 2;
}

Rechthoek Rechthoek::omvattend(Rechthoek r) const{
    int nlengte;
    int nbreedte;

    nlengte = grootste(lengte,r.lengte);
    nbreedte = grootste(breedte,r.breedte);

    Rechthoek _new(nlengte,nbreedte);
    _new.normalizeer();

    return _new;
}   

int Rechthoek::oppervlakte() const{
    return lengte*breedte;
}


class Vierkant: public Rechthoek {
    public:
        Vierkant(int zijde): Rechthoek(zijde,zijde){};
        virtual int oppervlakte();
};

int Vierkant::oppervlakte(){
    return lengte*breedte;
}
int main(){

    Rechthoek r1(10,11);
    Vierkant vier1(5);
    Vorm* vp = &r1;
    r1.drukaf();
    vier1.drukaf();
    cout << (*vp).oppervlakte();

}

