#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Complex {

    public:
        int real;
        int imaginary;

    Complex(int x, int y) {
        real = x;
        imaginary = y;
    }
    // Operator overloading for two complex numbers
    Complex operator+(Complex Z) {
        return Complex(real + Z.real, imaginary + Z.imaginary);
    }

    friend ostream& operator<<(ostream& os, Complex c) {
        os << c.real << " + " << c.imaginary << " i ";
        return os;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Complex z1(2, 3);
    Complex z2(5, 1);
    Complex z3 = z1 + z2;
    cout << z3;
    return 0;
}
