// Naam: Daan Sijnja Studentnummer: 20177747
#include <iostream>
using namespace std;

class Rechthoek{
    private:
        int lengte;
        int breedte;
        int grootste(int a, int b) const;
        void normalizeer();

    public:
        Rechthoek(int _lengte, int _breedte);
        void drukaf() const;
        int oppervlakte() const;
        void viervoud();
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

int Rechthoek::oppervlakte() const {
    return lengte*breedte;
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

class Vierkant: public Rechthoek{
    public:
        Vierkant(int zijde): Rechthoek(zijde,zijde){};
};

int main(){

    Vierkant a(7);
    Rechthoek b(1,3);

    a.drukaf();
    b.drukaf();


    return 0;
}


