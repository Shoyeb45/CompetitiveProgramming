#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


ll b, c, d;



void solve() {
    cin >> b >> c >> d;
    ll a = 0;
    ll mask = 1;
    for(int i = 0; i < 62; i++) {
        bool b1 = (b & mask), c1 = (c & mask), d1 = (d & mask);

        if((b1 && !c1 && !d1) || (!b1 && c1 && d1)) {
            cout << -1 << "\n";
            return;
        }
        if((!b1 && !c1 && d1) || (b1 && !c1 && d1) || (!b1 && c1 && !d1) || (b1 && c1 && !d1)) {
            a |= mask;
        }
        mask <<= 1;
    }

    cout << a << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}