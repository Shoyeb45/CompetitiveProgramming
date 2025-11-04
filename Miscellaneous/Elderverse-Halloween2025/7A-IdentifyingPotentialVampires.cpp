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
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore();
    map<string, int> mp;

    set<string> ans;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int j = 0;
        string _year = "";
        while (j < s.size()) {
            if (s[j] == ' ') {
                break;
            }
            _year += s[j++];
        }
        string name = s.substr(j + 1);

        int year = stoi(_year);
        if (mp.find(name) != mp.end()) {
           
            if (abs(mp[name] - year) >= 100) {
                ans.insert(name);
            }
            mp[name] = min(mp[name], year);
        } else {
            mp[name] = year;
        }
    }
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << "\n";
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

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}