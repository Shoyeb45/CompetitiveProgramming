#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll a, b;
void solve() {
    cin >> a >> b;
    
    if (a == b) {
        cout << "0 0\n";
        return; 
    }
    if (a == 0) {
        cout << b << " " << 0 << "\n";
        return;
    }
    if (b == 0) {
        cout << a << " " << 0 << "\n";
        return;
    }
    if (a < b) {
        swap(a, b);
    }

    ll mul = a - b;

    

    cout << (a - b) << " " <<  min(b % mul, mul - (b % mul)) << "\n";
}

int main() {
    NFS
   
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}