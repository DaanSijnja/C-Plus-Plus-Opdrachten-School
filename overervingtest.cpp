#include <iostream>
using namespace std;

class Voertuig{

    private:
        int wielen;
        int aantal_passasiers;
    public:
        void drukaf();
        Voertuig(int _wielen, int _aantalpassasiers);
}; 

Voertuig::Voertuig(int _wielen, int _aantalpassasiers){
    wielen = _wielen;
    aantal_passasiers = _aantalpassasiers;
}

Voertuig::drukaf(){

    
}


class Auto: public Voertuig{
    
    private:
        string model;
    public:
        void drukaf();
        Auto(int wielen, int Apassasiers, string _model);
};  

Auto::Auto(int wielen, int Apassasiers, string _model){
    Voertuig(wielen,Apassasiers);
    model = _model;
}



