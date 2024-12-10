#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
vector<int> a;
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a.push_back(x.size());
    }

    int curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        // curr += sum;
        if (curr + a[i] <= m) {
            curr += a[i];
        }
        else {
            ans = i;
            curr += a[i];
            break;
        }
    }
    if (curr <= m) {
        ans = n;
    }
    a.clear();
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