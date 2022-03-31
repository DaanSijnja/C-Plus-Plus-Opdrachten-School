#include <iostream>
using namespace std;

class Breuk {

    public:
        void print();
        Breuk();
        Breuk(int _teller);
        Breuk(int _teller, int _noemer);

        Breuk operator+=(Breuk andere_breuk);
        Breuk operator-=(Breuk andere_breuk);
        Breuk operator*=(Breuk andere_breuk);
        Breuk operator/=(Breuk andere_breuk);

        Breuk operator+(Breuk andere_breuk);
        Breuk operator-(Breuk andere_breuk);
        Breuk operator*(Breuk andere_breuk);
        Breuk operator/(Breuk andere_breuk);

    private:
        int teller;
        int noemer;
        void vereenvoudig();

};

Breuk::Breuk(){
    teller = 0;
    noemer = 0;
    vereenvoudig();
}

Breuk::Breuk(int _teller){
    teller = _teller;
    noemer = 1;
    vereenvoudig();
}

Breuk::Breuk(int _teller, int _noemer){
    teller = _teller;
    noemer = _noemer;
    vereenvoudig();
}

void Breuk::print(){
    cout << teller << '/' << noemer << endl;
}

void Breuk::vereenvoudig(){

    int a = noemer % teller;
    if(a == 0)
    {
        noemer = noemer/teller;
        teller = 1;
    }
    else
    {
        int t = teller % a;
        int n = noemer % a;

        if(t==0 && n==0)
        {
            teller = teller/a;
            noemer = noemer/a;
        }
    }
}

Breuk Breuk::operator+=(Breuk andere_breuk){
    if(noemer == andere_breuk.noemer)
    {
        teller = teller + andere_breuk.teller;
    }
    else
    {
        teller = teller * andere_breuk.noemer + andere_breuk.teller * noemer;
        noemer = noemer * andere_breuk.noemer;
    }
    vereenvoudig();

    return *this;
}

Breuk Breuk::operator-=(Breuk andere_breuk){
    if(noemer == andere_breuk.noemer)
    {
        teller = teller - andere_breuk.teller;
    }
    else
    {
        teller = teller * andere_breuk.noemer - andere_breuk.teller * noemer;
        noemer = noemer * andere_breuk.noemer;
    }
    vereenvoudig();

    return *this;
}

Breuk Breuk::operator*=(Breuk andere_breuk){
    noemer = noemer*andere_breuk.noemer;
    teller = teller*andere_breuk.teller;

    vereenvoudig();

    return *this;
}

Breuk Breuk::operator/=(Breuk andere_breuk){
    noemer = noemer*andere_breuk.teller;
    teller = teller*andere_breuk.noemer;

    vereenvoudig();

    return *this;
}

Breuk Breuk::operator+(Breuk andere_breuk){
    Breuk nieuwe_breuk(1,1);
    if(noemer == andere_breuk.noemer)
    {
        nieuwe_breuk.teller = teller + andere_breuk.teller;
        nieuwe_breuk.noemer = noemer;
    }
    else
    {
        nieuwe_breuk.teller = teller * andere_breuk.noemer + andere_breuk.teller * noemer;
        nieuwe_breuk.noemer = noemer * andere_breuk.noemer;
    }
    nieuwe_breuk.vereenvoudig();

    return nieuwe_breuk;
}

Breuk Breuk::operator-(Breuk andere_breuk){
    Breuk nieuwe_breuk(1,1);
    if(noemer == andere_breuk.noemer)
    {
        nieuwe_breuk.teller = teller - andere_breuk.teller;
        nieuwe_breuk.noemer = noemer;
    }
    else
    {
        nieuwe_breuk.teller = teller * andere_breuk.noemer - andere_breuk.teller * noemer;
        nieuwe_breuk.noemer = noemer * andere_breuk.noemer;
    }
    nieuwe_breuk.vereenvoudig();

    return nieuwe_breuk;
}

Breuk Breuk::operator*(Breuk andere_breuk){
    Breuk nieuwe_breuk(1,1);

    nieuwe_breuk.noemer = noemer*andere_breuk.noemer;
    nieuwe_breuk.teller = teller*andere_breuk.teller;

    nieuwe_breuk.vereenvoudig();

    return nieuwe_breuk;
}

Breuk Breuk::operator/(Breuk andere_breuk){
    Breuk nieuwe_breuk(1,1);

    nieuwe_breuk.noemer = noemer*andere_breuk.teller;
    nieuwe_breuk.teller = teller*andere_breuk.noemer;

    nieuwe_breuk.vereenvoudig();

    return nieuwe_breuk;
}

int main(){

    Breuk a(1,3);
    Breuk b(1,3);
    Breuk c(1,3);
 
    a = (a += b) += c;
    
    a.print();

    return 0;
}
