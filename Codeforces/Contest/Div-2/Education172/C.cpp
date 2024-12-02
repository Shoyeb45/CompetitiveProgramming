#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;

    ll alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bob += i;
        }
        else {
            alice += i;
        }
    }    

        debug("alice", alice, "bob", bob);
    int ans = -1;
    if (bob - alice >= k) {
        ans = n;
    }

    int cntOne = 0, cntZero = 0;
    int last = n - 1;

    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            cntOne++;
        }
        else {
            cntZero++;
        }

        if (s[i] == '1') {
            bob -= (last) + (cntOne - 1) * (last);
            bob += cntOne * (last);

            alice -= cntZero * last;
            alice += cntZero * (last - 1);
            last--;
        }
        else {
            alice -= (last) + (cntZero - 1) * (last);
            alice += cntZero * (last);

            bob -= cntOne * last;
            bob += cntOne * (last - 1);
            last--;

        }
        debug("zero", cntZero, "one", cntOne);
       
        debug("alice", alice, "bob", bob);
        // cout << n - (n - i) + 1 << "\n";
        if (bob - alice >= k) {
            ans = n - (n - i) + 1;
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}