#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll num;
void solve() {
    cin >> num;

    if ((num & 1) == 1) {
        cout << "YES\n";
        return;
    }

    ll temp = num;

    while (temp > 1) {
        temp /= 2; 
        if (temp > 1 && (temp & 1)) {
            cout << "YES\n";
            return;
        } 
    }
    cout << "NO\n";
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