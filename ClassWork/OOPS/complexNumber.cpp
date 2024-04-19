#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

class Complex {
    public:
        double real, imaginary;
        // double imaginary;
    Complex() {

    }
    Complex(double x, double y) {
        real = x;
        imaginary = y;
    }
    void printComplex();
    
};

void Complex::printComplex() {
    cout << real << " + " << "(" <<imaginary << ")" << " i";
}

int main() {
    Complex z;  
    z.real = 23;
    z.imaginary = 32;

    Complex y(12.3, 3.0);

    z.printComplex();
    cout << endl;
    y.printComplex();
    return 0;
}
