#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int cnt = 0, ans = 0;
        
        if((n % 2) == 0 && n >= 4) {
            if((n % 6) == 0)    cout << n/6 << " ";
            else    cout << n/6 + 1 << " ";

            cout << (n)/4 << "\n"; 
        } else {
            cout << -1 << "\n";
        }

    }
    return 0;
}
