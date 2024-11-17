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
    
    if (n == 2) {
        cout << "2 2\n"; 
    }
    else if(n == 3) {
        cout << "2 1 3\n";
    }
    else {
        if(n % 2 == 0) {
            for(int i = 1; i <= n - 2; i++) {
                cout << "1 ";
            }
            cout << "2 " << n << "\n";
        }
        else {
            for (int i = 1; i <= n - 3; i++) {
                cout << "1 ";
            }
            cout << "2 1 " << n << "\n";
        }
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