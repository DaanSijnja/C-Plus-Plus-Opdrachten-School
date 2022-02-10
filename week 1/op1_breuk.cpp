#include <iostream>

using namespace std;

class Breuk {
    private:
        int teller;
        int noemer;
        void vereenvoudig();
        int checkInput();
    public:
        void leesIn();
        void drukAf();
        void verhoogMet(Breuk andere_breuk);
};

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

int Breuk::checkInput(){
    int input;
    cin >> input;
    if(input > 0){
        return input;
    }
    else{
        cout << "getal moet groter zijn dan 0!" << endl << "voer nieuw getal in: ";
        
        checkInput();
    }
}

void Breuk::leesIn(){
    cout << "voer de teller in:";
    cin >> teller;
    cout << endl;
    cout << "voer de noemer in:";
    noemer = checkInput();
    cout << endl;
}

void Breuk::drukAf(){
    cout << "Breuk: " << teller << "/" << noemer;
}

void Breuk::verhoogMet(Breuk andere_breuk){
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
}



int main(){
    Breuk b;

    b.leesIn();
    b.drukAf();
    b.verhoogMet(b);
    b.drukAf(); 

    while(1)
    {}
    return 0;
}