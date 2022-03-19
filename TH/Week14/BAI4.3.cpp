/*Bài tập 3: Tính tích có hướng của 2 vector*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    /*# YOUR CODE HERE #*/
    double c1 = get<1>(a)*get<2>(b)-get<1>(b)*get<2>(a);
    double c2 = get<2>(a)*get<0>(b)-get<2>(b)*get<0>(a);
    double c3 = get<0>(a)*get<1>(b)-get<0>(b)*get<1>(a);

    return Vector(c1,c2,c3);
    /*****************/
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
