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
    int l, r;
    cin >> l >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> glimpse;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "=====") {
            break;
        }
        glimpse.push_back(s);
    }   
    vector<string> pat;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "=====") {
            break;
        }
        pat.push_back(s);
    }

    auto swap_col = [&](int i, int j) -> void {
        for (int k = 0; k < pat.size(); k++) {
            swap(pat[k][i], pat[k][j]);
        }
    };
    int idx = 0;

    for (int i = l; i <= r; i++) {
        cout << "idx: " << idx << "\n";
        map<char, set<int>> mp;
        for (int j = 0; j < glimpse[idx].size(); j++) {
            mp[glimpse[idx][j]].insert(j);
        }
        for (auto it: mp) {
            cout << it.first << " -> ";
            for (auto x: it.second) {
                cout << x << " ";
            }
            cout << "\n";
        }
        debug(pat[i]);
        for (int j = 0; j < pat[i].size(); j++) {
            debug(j);
            if (!mp[pat[i][j]].empty()) {
                int k = *mp[pat[i][j]].begin(); 
                debug(k);
                mp[pat[i][j]].erase(k);
                swap_col(k, j);
            }   
        }
        idx++;
    }

    for (auto s: pat) {
        cout << s << "\n";
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
        solve();
    }

    return 0;
}