#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> a(n);

    for(auto &x : a) {
        cin >> x;
    }

    int b[1001];
    memset(b, -1, sizeof(b));
    for(int i = 0; i < n; i++) {
        b[a[i]] = max(b[a[i]], i + 1);
    }

    int ans = 0;

    for(int i = 1; i <= 1000; i++) {
        if(b[i] != -1) {
            if(i == 1) {
                ans = max(ans, b[i] * 2);
            }

            for(int j = 1; j <= 1000; j++) {
                if(b[j] != -1) {
                    if(__gcd(j, i) == 1) {
                        ans = max(ans, b[i] + b[j]);
                    }
                }
            }
        }
    }

    cout << (ans == 0 ? -1 : ans) << "\n";
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