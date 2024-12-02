#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int temp = 1;
        for (int j = i + 1; j < n - 1; j++) {
            if (a[j + 1] > a[j]) {
                break;
            }
            temp++;
        }
        
        for (int j = i; j >= 1; j--) {
            if (a[j - 1] > a[j]) {
                break;
            }
            temp++;
        }
        ans = max (ans, temp);
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