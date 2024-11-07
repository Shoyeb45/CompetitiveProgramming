#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
string a, b;

char flip(char a) {
    return a == 'H' ? 'G' : 'H';
}

void solve() {
    cin >> n >> a >> b;

    int ans = 0;

    for (int i = 0; i < n;) {
        if (a[i] == b[i]) {
            while(i < n && a[i] == b[i]) {
                i++;
            }
            continue;
        }
        else {
            while (i < n && b[i] == flip(a[i])) {
                i++;
            }
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}