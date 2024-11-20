#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;

void print(int x, int y) {
    if (x == y) {
        cout << x << "=" << y << "\n";
    }
    else if (x > y) {
        cout << x << ">" << y << "\n";
    }
    else {
        cout << x << "<" << y << "\n";
    }
}
void solve() {
    cin >> s;

    int x = s[0] - '0', y = s[2] - '0';
    char ch = s[1];

    if (ch == '=') {
        if (x == y) {
            cout << s << "\n";
        }
        else {
            print(x, y);
        }
    }
    else if (ch == '<') {
        if (x < y) {
            cout << s << "\n";
        }
        else {
            print(x, y);
        }
    }
    else {
        if (x > y) {
            cout << s << "\n";
        }
        else {
            print(x, y);
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
    int tt;.
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}