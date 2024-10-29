#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
void solve() {
    cin >> s;
    int n = s.size();
    vector<int> suff(n, 0);  // Suffix sum array of 'Q' till index i from last
    suff[n - 1] = (s[n - 1] == 'Q');

    for(int i = n - 2; i >= 0; i--) {
        suff[i] += suff[i + 1] + (s[i] == 'Q');
    }
    int pref = 0; // Running pref count of 'Q'

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        pref += (s[i] == 'Q');
        if(s[i] == 'A') {
            ans += pref * suff[i];  // Add pref * suff
        }
    }

    cout << ans << "\n";  // Output answer
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