#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void printPolynomial(int n, int i) {
    if(i == n - 1) {
        cout << "x^" << i << endl;
        return;
    }

    if(i == 0) {
        cout << 1 << " + ";
    }else
        cout << "x^" << i << " + ";
    printPolynomial(n, i+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    printPolynomial(t, 0);
    return 0;
}
