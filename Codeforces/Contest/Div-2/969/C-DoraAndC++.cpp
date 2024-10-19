#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, a, b;
void solve() {
    cin >> n >> a >> b;
    int g = __gcd(a, b);
    set<int> c;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c.insert(x % g);
    }

    int ans = INT_MAX, prev = 0;
    

    for(auto it = c.begin(); it != c.end(); it++) {
        if(it == c.begin()) {
            ans = min(ans, *c.rbegin() - *it);
        }
        else {
            ans = min(ans, prev + g - *it);
        }
        prev = *it;
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