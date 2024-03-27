#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> x(n);
        
        for (int i = 0; i < n; i++) cin >> x[i];

        ll seconds = 0, c = b;
        ll i = 0;
        while (true)
        {
            if(c > 1) {
                seconds += (c - 1);
                c = 1;
            } else if(c == 1) {
                c = min(c + x[i], a);
                c--;
                i++;
                seconds++;
            } else {
                seconds++;
                break;
            }

            if(i == n - 1) {
                seconds += (c);
                break;
            }
        }
        cout << seconds <<"\n";
    }
    
}