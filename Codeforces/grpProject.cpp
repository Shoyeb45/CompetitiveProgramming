#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int xa = 0, xb = 0;
        for(int i = 7; i < 10 ; i++) {
            xa = xa * 10 + (a[i] - '0');
            xb = xb * 10 + (b[i] - '0');
        }
    }
    
}