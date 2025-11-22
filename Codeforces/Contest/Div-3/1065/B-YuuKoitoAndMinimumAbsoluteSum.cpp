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
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& x: a) cin >> x;

    if (a[0] == -1 && a[n - 1] == -1) {
        cout << 0 << "\n";
        for (auto &x: a) {
            cout << (x == -1 ? 0 : x) << " ";
        }
        cout << '\n';
        return;
    }

    if (a[0] == -1 && a[n - 1] != -1) {
        cout << 0 << "\n";
        cout << a[n - 1] << " ";
        for (int i = 1; i < n; i++) {
            cout << (a[i] == -1 ? 0 : a[i]) << " ";
        }
        cout << "\n";
        return;
    } 
    
    if (a[0] != -1 && a[n - 1] == -1) {
        cout << 0 << "\n";
        for (int i = 0; i < n - 1; i++) {
            cout << (a[i] == -1 ? 0 : a[i]) << " ";
        }
        cout << a[0] << " \n";
        return;
    }
    
    cout << abs(a[n - 1] - a[0]) << "\n";
    for (int i = 0; i < n; i++) {
        cout << (a[i] == -1 ? 0 : a[i]) << " ";
    }
    cout << "\n";
}   


void elegant_solution() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    
    int ones = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        ones += (a[i] == 1) + (b[i] == 1);
    }

    if (ones % 2 == 0) {
        cout << "Tie\n";
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] != b[i]) {
            cout << (i % 2 == 0 ? "Mai" : "Ajisai") << "\n";
            return;
        }
    }
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
        elegant_solution();
    }

    return 0;
}