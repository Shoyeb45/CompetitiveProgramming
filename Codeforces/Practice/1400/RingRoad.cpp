#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
bool from[101] = {0};
bool to[101]= {0};

void solve() {
    cin >> n;

    ll ans1 = 0, sum = 0;
    for(int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        sum += c;
        if(from[a] || to[b]) {
            from[b] = to[a] = 1;
            cerr << a << "->" << b << '\n';
            ans1 += c;
        }
        else {
            // from a -> b
            from[a] = to[b] = 1;
        }
    }    
    cout << min(ans1, sum - ans1) << "\n";
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