#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<bool> isPrime(2e5 + 1, 1);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n - 1; i++) {
        if (isPrime[a[i] + a[i + 1]]) {
            cout << "false\n";
            return;
        }
    }
    cout << "true\n";
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
    isPrime[1] = false;
    for (int i = 2; i <= 2e5; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= 2e5; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    while (tt--) {
        solve();
    }

    return 0;
}