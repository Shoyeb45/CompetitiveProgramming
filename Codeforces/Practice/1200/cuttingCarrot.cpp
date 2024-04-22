#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll; 
typedef long double ld; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, h;
    cin >> n >> h;    
    ld x = sqrt(ld(n));

    for(int i = 1; i <= n - 1; i++) {
        ld ans = ((sqrt(ld(i)))/ld(x)) * ld(h);
        cout << fixed << setprecision(12) << ans << "";
        if(i < n - 1)   
            cout << " ";
    }
    cout << endl;
    return 0;
}
