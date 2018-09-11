
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    double a, b, c, disc, xs, xr, xi, x1, x2;
    cout << "enter your a, b, c in order, press enter after each one you entered:" << endl;
    cin >> a >> b >> c;
    
    if (((a == 0) && (b == 0)) || (c == 0)) {
        cout << "Unable to determine root(s).";
    }
    else if (a == 0){
        xs = -c / b;
        cout << b << "x + " << c << " = 0" << endl;
        cout << "x = " << xs;
    }
    else{
        disc = b * b - 4 * a * c;
        if (disc >= 0){
            x1 = (-b - sqrt (disc)) / (2 * a);
            x2 = (-b + sqrt (disc)) / (2 * a);
            cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
            cout << "x = " << x1 << endl;
            cout << "x = " << x2;
        }
        else{
            xr = -b / (2 * a);
            xi = sqrt (-disc) / (2 * a);
            cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
            cout << "x = " << xr << " - " << xi << "i" << endl;
            cout << "x = " << xr << " + " << xi << "i" << endl;
        }
    }
    return 0;
}
