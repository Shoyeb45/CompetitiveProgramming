#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0, prod = 1, negativeNo = 0;
        for (int i = 0 ; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            prod *= a[i];
        }

        for(int i = 0; ; i++) {
            if(sum >= 0 && prod == 1) {
                cout << i << '\n';
                break;
            }
            prod *= -1;
            sum += 2;
        }
    }
}