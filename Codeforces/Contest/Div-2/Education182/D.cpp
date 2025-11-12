#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    ll y;
    cin >> n >> y;
    vector<ll> a(n);
    ll A = LLONG_MIN;
    
    for (ll &x: a) {
        cin >> x;
        A = max(A, x);
    }   
    A++;
    vector<ll> cnt(A, 0), pref(A, 0);

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }   
    for (int i = 1; i < A; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }

    if (A == 2) {
        cout << n << "\n";
        return;
    }

    ll ans = LLONG_MIN;
    for (ll x = 2; x < A; x++) {
        ll result = 0;
        ll max_p = (A + x - 2) / x;
        for (ll p = 1; p <= max_p; p++) {
            int l = (p - 1) * x + 1;
            int r = min((ll)A - 1, p * x);
            
            ll need = pref[r] - pref[l - 1];
            ll extra = max(0LL, need - cnt[p]);
            result += p * need - y * extra;
        }
        ans = max(result, ans);
    }
    cout << ans << "\n";
    
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