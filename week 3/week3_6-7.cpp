// Naam: Daan Sijnja Studentnummer: 20177747
#include<iostream>
using namespace std;

class Length {
    private:
        int feet;
        int inches;
        void normalizeer();
    public:
        Length(int _feet, int _inches);
        Length(int _inches);
        Length();

        void drukAf();
        void distance(Length l);
        Length largest(Length l);
        int smallest(int _cm);
        int centimeters() const;

        Length operator+(Length l);
};

Length::Length(){
    feet = 0;
    inches = 0;
}

Length::Length(int _feet, int _inches){
    feet = _feet + _inches / 12;
    inches = _inches % 12;
}

Length::Length(int _inches){
    feet = _inches / 12;
    inches = _inches % 12;
}

void Length::normalizeer(){
    feet = feet + inches / 12;
    inches = inches % 12;
}

int Length::centimeters() const {
    int total_cm;

    total_cm = (12*feet + inches)*2.54;

    return total_cm;
}

void Length::drukAf(){
    int totaal_cm = centimeters();
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

Length Length::largest(Length l){
    
    if(l.centimeters() > centimeters()){
        return l;
    }
    else
    {
        return *this;
    }

}

int Length::smallest(int _cm){
    
    if(_cm > centimeters())
    {
        return centimeters();
    }
    else
    {
        return _cm;
    }
}

Length Length::operator+(Length l){
    int _feet = feet + l.feet;
    int _inches = inches + l.inches;

    Length new_length(_feet,_inches);

    return new_length;
}

class Voorwerp{
    private:
        Length length;
        int nummer;
    
    public:
        Voorwerp(Length l);
        void drukaf();
};

Voorwerp::Voorwerp(Length l){
    length = l;
    nummer = -1;
}

void Voorwerp::drukaf(){
    length.drukAf();
    cout << nummer << endl;
}

int main(){

    Length l1(2,2);

    Voorwerp v1(l1);
    v1.drukaf();


    return 0;
}