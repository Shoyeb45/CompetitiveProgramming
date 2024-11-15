#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int factors[(int)(1e6 + 1)];
int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    bool isAlice = 1;

    for (auto x : a) {
        int y = factors[x];
        int k = x / y;
        // debug("k", k);
        if (x % y == 0) {
            if (k % 2 == 1) {
                isAlice = !isAlice;
            }
        }
        else {
            if (k % 2 == 1) {
                isAlice = !isAlice;
            }
        }
  
        // cout << (isAlice? "Alice": "Bob") << "\n";
    }

    cout << (!isAlice? "Alice": "Bob") << "\n";
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
    memset(factors, 0, sizeof(factors));
    factors[1] = 1;
    bool isPrime[(int)(1e6 + 1)];
    for (int i = 2; i <= 1e6; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= 1e6; i++) {
        if (isPrime[i]) {
            factors[i] = 1;
            for (ll j = 2 * i; j <= 1e6; j += i) {
                isPrime[j] = false;
                factors[j]++; 
            }
        }
    }

    // for (int i = 1; i <= 100; i++) {
    //     cout << factors[i] << " \n"[i == 100];
    // }
    while (tt--) {
        solve();
    }

    return 0;
}