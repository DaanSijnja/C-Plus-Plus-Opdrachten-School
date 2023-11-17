#include <iostream>
using namespace std;

class Vierkant{
 private:
 int breedte;
 public:
 Vierkant(int grootte);
 virtual void toonOppervlakte();
};
Vierkant::Vierkant(int grootte){
 breedte = grootte;
}
void Vierkant::toonOppervlakte(){
 cout << breedte * breedte << endl;
}
class Rechthoek: public Vierkant{
 private:
 int lengte;
 public:
 Rechthoek(int l, int b);
 void toonOppervlakte();
};
Rechthoek::Rechthoek(int l, int b): Vierkant(b){
 lengte = l;
}
void Rechthoek::toonOppervlakte(){
 cout << lengte * breedte << endl;
}


int main()
{
 Vierkant v(7);
 v.toonOppervlakte();
 
 Rechthoek r(4, 6);
 r.toonOppervlakte();
 
 Vierkant& v1 = r;
 v1.toonOppervlakte();
 return 0;
}
