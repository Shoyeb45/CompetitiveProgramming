#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<int> a;
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> freq(31);
    for(int i = 0; i <= 30; i++) {
        for(auto x: a) {
            freq[i] += !(bool)((1 << i) & x);
        }
    }

    for(int i = 30; i >= 0; i--) {
        if(freq[i] == 0) {
            continue;
        }
        if(freq[i] <= k) {
            k -= freq[i];
            for(auto &x: a) {
                x = ((1 << i) | x);
            }
        }
    }

    ll ans = a.front();
    for(int i = 1; i < n; i++) {
        ans &= a[i];
    }
    cout << ans << "\n";

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