// Naam: Daan Sijnja Studentnummer: 20177747
#include<iostream>
using namespace std;

class Length {
    private:
        int feet;
        int inches;
        int rekenOm();
    public:
        Length(int _feet, int _inches){
            feet = _feet + _inches / 12;
            inches = _inches % 12;
        }

        Length(int _inches){
            feet = _inches / 12;
            inches = _inches % 12;
        }
        void leesIn(int feet, int inches);
        void drukAf();
        void distance(Length l1);
};

int Length::rekenOm(){
    int total_cm;

    total_cm = (12*feet + inches)*2.54;

    return total_cm;
}

void Length::leesIn(int _feet, int _inch){
    feet = _feet;
    inches = _inch;
}

void Length::drukAf(){
    int totaal_cm = rekenOm();
    int cm = totaal_cm % 100;
    int meter = totaal_cm / 100;
    cout << "Feet: " << feet << " Inches: " << inches << endl;
    cout << "Meter: " << meter << " Centimeter: " << cm << endl;
}

void Length::distance(Length l2){

    int l1_inches = (feet*12 + inches);
    int l2_inches = (l2.feet*12 + l2.inches);
    int verschilInInch;
    if(l1_inches > l2_inches){
        verschilInInch = l1_inches - l2_inches;
    }
    else{
        verschilInInch = l2_inches - l1_inches;
    }
        
    cout << "Verschil[ " << "Feet: " << verschilInInch / 12 << " Inches: " << verschilInInch % 12 << " ]"<< endl;
}

int main(){

    Length l1(60);
    Length l2(2,2);
    l1.drukAf();
    l2.drukAf();
    l1.distance(l2);
    return 0;
}