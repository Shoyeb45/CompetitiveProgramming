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


pair<string, int> process_ingredient(string ing) {
    ing.erase(0, ing.find_first_not_of(" \t\n\r\f\v"));
    string temp = "", qnt = "";
    for (int i = 0; i < ing.size(); i++) {
        char ch = ing[i];

        if (ch == '(') {
            for (int j = i + 1; j < ing.size(); j++) {
                if (ing[j] == ')') {
                    break;
                }
                qnt += ing[j];
            }
            break;
        } else {
            temp += ch;
        }
    }
    return make_pair(temp, stoi(qnt));
}

void solve() {
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string ing;
        getline(cin, ing);
        auto [s, qnt] = process_ingredient(ing);
        mp[s] += qnt;
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        string ing;
        getline(cin, ing);
        string temp = "";
        bool ok = true;
        map<string, int> t_mp;
        for (int i = 2; i < ing.size(); i++) {
            if (ing[i] == ',') {
                auto [s, qnt] = process_ingredient(temp);
                t_mp[s] += qnt;
                temp = "";
            } else {
                temp += ing[i];
            }
        }
        auto [s, qnt] = process_ingredient(temp);
        t_mp[s] += qnt;

        for (auto it: t_mp) {
            if (it.second > mp[it.first]) {
                ok = false;
                break;
            }
        }

        ans += ok;
    }
    cout << ans << "\n";
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