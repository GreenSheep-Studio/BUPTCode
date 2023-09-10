#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double CalcTime(double a, double v, double l, double d, double w){
    if (v < w) {
        if ((v * v) / (2 * a) >= l) return sqrt(2 * l / a );
        else if ((v * v) / (2 * a) < l) {
            double x = (v * v) / (2 * a);
            l = l - x;
            double t1 = v / a;
            double t2 = l / v;
            return (t1 + t2);
        }
    }
    else if (v >= w) {
        double t1, t2, t3, t4;
        t1 = t2 = t3 = t4 = 0;
        if ((w * w) / (2 * a) >= d) {
            t1 = sqrt(2 * d / a );
            double y = sqrt(2 * d * a);
            if (((v * v)- (y * y)) / (2 * a) >= (l - d)){
                double z = sqrt((l - d) * 2 * a + (y * y));
                t2 = (z - y) / a;
            }
            else if (((v * v)- (y * y)) / (2 * a) < (l - d)){
                double x = ((v * v)- (y * y)) / (2 * a);
                t2 = (v - y) / a;
                t3 = (l - d - x) / v;
            }
        }
        else if ((w * w) / (2 * a) < d) {
            double x = (w * w) / (2 * a);
            t1 = w / a;
            if (((v * v) - (w * w)) / 2 / a >= (2* (d - x))) {
                t2 = (-2 * w + sqrt(4 * w * w + (4 * a * (d - x)))) / a;
            }
            else if (((v * v) - (w * w)) / 2 / a < (2* (d - x))) {
                t2 = ((d - x - ((v * v - w * w) / a)) / v) + 2 * ((v - w) / a);
            }
            if (((v * v)- (w * w)) / (2 * a) >= (l - d)){
                double y = sqrt((l - d) * 2 * a + (w * w));
                t3 = (y - w) / a;
            }
            else if (((v * v)- (w * w)) / (2 * a) < (l - d)){
                double x = ((v * v)- (w * w)) / (2 * a);
                t3 = (v - w) / a;
                t4 = (l - d - x) / v;
            }
        }
        return (t1 + t2 + t3 + t4);
    }
}

int main ()
{
    double a, v;
    double l, d, w;
    double Time;
    cin >> a >> v;
    cin >> l >> d >> w;
    cout << fixed << setprecision(10)<< CalcTime(a, v, l, d, w) << endl;
    system("PAUSE");
    return 0;
}