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
const set<string> ptrns = {">*", "*<", "**", "><"};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    if (s[0] == '*' && s[n - 1] == '*') {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        string temp = s.substr(i, 2);
        debug(temp);
        if (ptrns.find(temp) != ptrns.end()) {
            cout << -1 << "\n";
            return;
        }
    }

    ll ans = 0;
    int i = 0;
    if (s[i] == '*') {
        i++;
    }
    if (s[i] == '>') {
        cout << s.size() << "\n";
        return;
    }
    for (; i < n; i++) {
        if (s[i] == '>') {
            break;
        }
    }
    ans = i;

    ll temp = n - i;
    if (i < n && i - 1 < n && s[i - 1] == '*') {
        temp++;
    }
    cout << max(ans, temp) << "\n"; 

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