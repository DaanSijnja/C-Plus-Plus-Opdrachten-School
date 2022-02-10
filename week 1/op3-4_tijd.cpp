#include <iostream>

using namespace std;

class Tijd {
    public:
        void leesIn();
        void drukAf();
        void verhoog(int minuten);
        void verschil(Tijd tijd);
    private:
        int tijd_in_minuten;
};

void Tijd::leesIn(){
    int uren;
    int minuten;
    cout << "Voer het aantal uren in: ";
    cin >> uren;
    cout << "Voer het aantal minuten in: ";
    cin >> minuten;

    tijd_in_minuten = uren*60 + minuten;
}

void Tijd::drukAf(){
    cout << "Tijd: " << tijd_in_minuten/60 << ":" << tijd_in_minuten%60;
}

void Tijd::verhoog(int minuten){
    tijd_in_minuten = tijd_in_minuten += minuten;
}

void Tijd::verschil(Tijd tijd){

    if(tijd_in_minuten < tijd.tijd_in_minuten)
    {
        int verschil = tijd.tijd_in_minuten - tijd_in_minuten;
        cout << "Het verschill is: " << verschil/60 << ":" << verschil % 60;
    }
    else
    {
        int verschil = tijd_in_minuten - tijd.tijd_in_minuten ;
        cout << "Het verschill is: " << verschil/60 << ":" << verschil % 60;
    }


}

int main(){

    Tijd t1;
    Tijd t2;

    t1.leesIn();
    t1.drukAf();

    t2.leesIn();
    t2.drukAf();



    return 0;
}

