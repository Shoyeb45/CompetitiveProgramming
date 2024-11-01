#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<string> a;
void solve() {
    int numRow = 0;
    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        bool check = true;
        for(char c: s) {
            if(c == '#') {
                check = false;
                break;
            }
        }
        numRow += (int)check;
        a.push_back(s);
    }

    int numCol = 0;
    for(int i = 0; i < 8; i++) {
        bool check = true;
        for(int j = 0; j < 8; j++) {
            if(a[j][i] == '#') {
                check = false;
                break;
            }
        }
        numCol += (int)check;
    }

    cout << 1LL * numCol * numRow << "\n";
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