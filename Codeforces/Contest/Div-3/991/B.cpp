#include<bits/stdc++.h>
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

    ll odd = 0, even = 0;
    ll cntOdd = 0, cntEven = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (i % 2 == 1) {
            cntOdd++;
            odd += x;
        }
        else {
            cntEven++;
            even += x;
        }
    }    


    if (even % cntEven == 0 && odd % cntOdd == 0 && even / cntEven == odd / cntOdd) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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