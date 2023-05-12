#include <iostream>
using namespace std;

class circle
{
    public:
    void GetR(double Radius){
        r = Radius;
    }
    void CalcC(double Radius){
        cout << 2 * pi * r << " ";
    }
    void CalcS(double Radius){
        cout << pi * r * r;
    }
    private:
    const double pi = 3.14;
    double r;
    double C;
    double S;
};
int main ()
{
    double R;
    cin >> R;
    circle c;
    c.GetR(R);
    c.CalcC(R);
    c.CalcS(R);
    system ("PAUSE");
    return 0;
}