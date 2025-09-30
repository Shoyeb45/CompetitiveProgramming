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
int n, x;


// Since for any 
void solve() {
    cin >> n;

    static int mp[(int)1e6 + 1]; 
    fill(mp, mp + (int)1e6 + 1, 0);

    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mx = max(x, mx);
        mp[x]++;
    }
    int ans = 1;

    for (int i = mx; i > 1; i--) {
        int freq = 0;
        bool ok = false;

        for (ll j = i; j <= mx; j += i) {
         
            freq += mp[j];
            if (freq >= 2) {
                ans = i;
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    
    return 0;
}