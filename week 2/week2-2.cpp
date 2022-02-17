#include <iostream>

using namespace std;

class Tijd {
    public:
        void leesIn();
        void drukAf();
        void verhoog(int minuten);
        void verhoog(Tijd tijd);
        void verschil(Tijd tijd);

        Tijd();
        Tijd(int _minuten);
        Tijd(int _uren, int _minuten);
    private:
        int tijd_in_minuten;
};

Tijd::Tijd(){
    tijd_in_minuten = 0;
}

Tijd::Tijd(int _minuten){
    tijd_in_minuten = _minuten;
}

Tijd::Tijd(int _uren, int _minuten){
    tijd_in_minuten = _uren*60 + _minuten;
}

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
    cout << "Tijd: " << tijd_in_minuten/60 << ":" << tijd_in_minuten%60 << endl;
}

void Tijd::verhoog(int _minuten){
    tijd_in_minuten = tijd_in_minuten + _minuten;
}

void Tijd::verhoog(Tijd tijd){
    tijd_in_minuten = tijd_in_minuten + tijd.tijd_in_minuten;
}

void Tijd::verschil(Tijd tijd){

    if(tijd_in_minuten < tijd.tijd_in_minuten)
    {
        int verschil = tijd.tijd_in_minuten - tijd_in_minuten;
        cout << "Het verschill is: " << verschil/60 << ":" << verschil % 60 << endl;
    }
    else
    {
        int verschil = tijd_in_minuten - tijd.tijd_in_minuten ;
        cout << "Het verschill is: " << verschil/60 << ":" << verschil % 60 << endl;
    }


}

int main(){

    Tijd t1;
    Tijd t2;

    t1.leesIn();
    t1.drukAf();

    t2.leesIn();
    t2.drukAf();

    t1.verschil(t2);

    t1.verhoog(t2);

    t1.drukAf();

    return 0;
}