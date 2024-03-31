#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int  n, k, x;
        cin >> n >> k >> x;
        
        if(x != 1) {
            cout << "YES\n" << n << "\n";
            for(int i = 0 ; i < n; i++) cout << 1 << " " ;
            cout << endl;
        } else {
            if(n % 2 == 0 && k >= 2)  {
                cout << "YES\n" << n/2 << "\n";
                for(int i = 0 ; i < n/2; i++) cout << 2 << " ";
                cout << endl;
            } else {
                if(k <= 2)  cout << "NO\n";
                else {
                    cout << "YES\n" << n/2 << endl;
                    for(int i = 0 ; i < (n/2) - 1; i++) cout << 2 << " " ;
                    cout << 3 << endl;
                }
            }
        }
    } 
}