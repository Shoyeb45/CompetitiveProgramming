#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<string> a;

void print(vector<string> &a) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}
void solve() {
    cin >> n;   
    a.resize(n + 1, " ");
    for(int i = 1; i <= n; i++) {
        string s; 
        cin >> s;
        a[i] += s;
    }   
    print(a);
    for(int i = 1; i <= n / 2; i++) {
        cout << "i : " << i << "\n";
        for(int x = i; x <= n - i + 1; x++) {
            for(int y = x; y <= (n - i + 1) ; y++) {
                a[y][n - i + 1] = a[x][y];
            }
        }
        print(a);
        cout << endl;
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}