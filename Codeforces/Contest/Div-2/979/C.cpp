#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
string s;
void solve() {
    cin >> n >> s;
    int one = 0;
    for(auto ch : s) {
        one += (ch == '1');
    }

    if(2 * one >= n) {
        cout << "YES\n";
    }
    else {
        if(n % 2 == 0 && 2 * one == n) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    }
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