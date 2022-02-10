#include <iostream>

using namespace std;

struct TIJD {
    int uren;
    int minuten;

} ;

TIJD t1;
TIJD t2;

TIJD verschillTijdStippen(TIJD t1, TIJD t2){
    TIJD verschil;

    verschil.minuten = -1;
    verschil.uren = -1;

    if(t1.uren < t2.uren || (t1.uren == t2.uren && t1.minuten <= t2.minuten))
    {   
        verschil.uren = t2.uren - t1.uren;
        verschil.minuten = t2.minuten - t1.minuten;

        if(verschil.minuten < 0)
        {
            verschil.uren = verschil.uren - 1;
            verschil.minuten = 60 + verschil.minuten;
        }

    }
    
    return verschil;

}


TIJD voerTijdIn(){
    TIJD t;
    cout << "Uren: ";
    cin >> t.uren;  
    cout << "Minuten: ";
    cin >> t.minuten;

    return t;
}


int main(){
    cout << "Voer T1 in:" << endl;
    TIJD t1 = voerTijdIn();
    cout << t1.uren << ":" << t1.minuten << endl;

    cout << "Voer T2 in:" << endl;
    TIJD t2 = voerTijdIn();
    cout << t2.uren << ":" << t2.minuten << endl;

    TIJD verschil = verschillTijdStippen(t1, t2);

    if(verschil.minuten == -1)
    {
        cout << "T1 ligt na T2!" << endl;
    }
    else
    {
        cout << "Verschil tussen T1 en T2!" << endl;
        cout << verschil.uren << ":" << verschil.minuten << endl;
    }

    return 0;
}