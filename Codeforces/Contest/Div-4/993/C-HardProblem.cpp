#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll m, a, b, c;
void solve() {
    cin >> m >> a >> b >> c;
    ll ans = 0;
    ll temp = m;
    if (a <= m) {
        ans += a;
        temp -= a;
        a = 0;
        if (c <= temp) {
            ans += c;
            temp -= c;
            c = 0;
        }
        else {
            ans += temp;
            c -= temp;
            temp = 0;
        }
    }
    else {
        ans += temp;
        a -= temp;
        temp = 0;
    }

    temp = m;
    if (b <= m) {
        ans += b;
        temp -= b;
        b = 0;
        if (c <= temp) {
            ans += c;
            temp -= c;
            c = 0;
        }
        else {
            ans += temp;
            c -= temp;
            temp = 0;
        }
    }
    else {
        ans += temp;
        b -= temp;
        temp = 0;
    }
    cout << ans << '\n';
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}