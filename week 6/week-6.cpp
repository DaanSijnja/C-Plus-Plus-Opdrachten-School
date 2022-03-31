// Naam: Daan Sijnja Studentnummer: 20177747
#include <iostream>
using namespace std;

class Ontwerper{
    protected:
        Ontwerper* partner = 0;

    public:
        virtual float salaris();
        float totaleKosten();
        void nieuwePartner(Ontwerper* ontwerper);
};  

float Ontwerper::salaris(){
    return 0.0;
}

float Ontwerper::totaleKosten(){
    float totale_salaris;
    totale_salaris = salaris();
    if(partner != 0){
        totale_salaris += (*partner).salaris();
    }

    return totale_salaris;
}

void Ontwerper::nieuwePartner(Ontwerper* ontwerper){
    if(partner != NULL){
        (*partner).partner = NULL;
    }

    partner = ontwerper;
    (*ontwerper).partner = this;
}

class Freelancer : public Ontwerper{
    private:
        float uurloon;
        int gewerkte_uren;

    public:
        virtual float salaris();
        Freelancer(float _uurloon, int _gewerkte_uren);
};

Freelancer::Freelancer(float _uurloon, int _gewerkte_uren){
    uurloon = _uurloon;
    gewerkte_uren = _gewerkte_uren;
}

float Freelancer::salaris(){
    float salaris = uurloon*gewerkte_uren;
    return salaris;
}

class VasteKracht : public Ontwerper{
    private:
        float maandsalaris;
    
    public:
        virtual float salaris();
        VasteKracht(float _maandsalaris);
};

VasteKracht::VasteKracht(float _maandsalaris){
    maandsalaris = _maandsalaris;
}

float VasteKracht::salaris(){
    return maandsalaris;
}

void berekenSalaris(Ontwerper* ontwerper){

    cout << "het salaris is: " << (*ontwerper).salaris() << " per maand";
}


int main(){

    Freelancer jake(80.0,150);
    VasteKracht henk(3000);
    Freelancer paul(90.0,120);

    henk.nieuwePartner(&jake);

    cout << "henk + jake: " << henk.totaleKosten() << endl;
    cout << "jake + henk: " << jake.totaleKosten() << endl;
    cout << "paul: " << paul.totaleKosten() << endl;

    jake.nieuwePartner(&paul);

    cout << "henk: " << henk.totaleKosten() << endl;
    cout << "jake + paul: " << jake.totaleKosten() << endl;
    cout << "paul + jake: " << paul.totaleKosten() << endl;
    return 0;
}