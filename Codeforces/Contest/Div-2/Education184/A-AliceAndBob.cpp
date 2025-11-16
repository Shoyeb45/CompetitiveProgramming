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
    int n, b;
    cin >> n >> b;
    vector<int> a(n);

    for (int &x: a) {
        cin >> x;
    }
    
    int b1 = b + 1, b2 = b - 1;
    
    int cnt1 = 0, cnt2 = 0;
    for (auto x: a) {
        if (abs(x - b1) < abs(x - b)) {
            cnt1++;
        }
        if (abs(x - b2) < abs(x - b)) {
            cnt2++;
        }
    }
    
    if (cnt1 >= cnt2) {
        cout << b1 << "\n";
        return;
    }
    cout << b2 << "\n";
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