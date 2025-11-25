#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    int c = count(range(s), '4');

    if (x == 0 && y == 0) {
        cout << "YES\n";
        return;
    }

    int _x = n, _y = n;
    if (x < 0) {
        x = -x;
    } 
    if (y < 0) {
        y = -y;
    }

    if (x > _x || y > _y) {
        cout << "NO\n";
        return;
    }
    bool ok = true;

    for (int i = 0; i < c; i++) {
        int Y = _y - i;
        // x - c - 1
        int temp_x = _x - (c - 1 - i);
        debug(Y, temp_x);
        if (y == Y && x >= temp_x && x <= _x) {
            ok = false;
            break;
        }
    }
    
    if (ok) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}