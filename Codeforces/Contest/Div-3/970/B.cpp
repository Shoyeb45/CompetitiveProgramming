#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
string s;
bool allOne(string s) {
    for(auto ch: s) {
        if(ch == '0') {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> s;

    if(allOne(s)) {
        if(n == 4) {
            cout << "YES\n";
        }
        else {
            cout << "No\n";
        }
        return;
    }

    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            ind = i + 1;
            break;
        }
    }

    int col = ind - 2;
    int row = n / col;

    cout << (col == row? "YES\n": "NO\n");
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
