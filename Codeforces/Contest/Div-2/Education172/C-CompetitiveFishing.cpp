#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;

    vector<ll> pref;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        pref.push_back(sum);
        sum += (s[i] == '1'? 1: -1);
    }    

    sort(pref.rbegin(), pref.rend());

    int ans = 0;
    sum = 0;
    
    for (int i = 0; i < pref.size(); i++) {
        sum += pref[i], ans++;
        if (sum >= k) {
            cout << ans + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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