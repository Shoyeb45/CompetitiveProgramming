#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, q;
void solve() {
    cin >> n >> q;

    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int t;

    int lastSecondQuery = -1, lastSecondVal = 0;
    vector<ll> lastFirstQuery(n, 0);

    for (int j = 1; j <= q; j++) {
        cin >> t;
        
        if(t == 1) {
            ll i, x;
            cin >> i >> x;
            i--;

            if (lastSecondQuery > lastFirstQuery[i]) {
                sum -= lastSecondVal;
            }
            else {
                sum -= a[i];
            }

            sum += x;
            
            a[i] = x;
            lastFirstQuery[i] = j;
        }
        else {
            int x;
            cin >> x;
            lastSecondQuery = j;
            lastSecondVal = x;
            sum = (1LL * n * x);
        }

        cout << sum << "\n";
    }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}