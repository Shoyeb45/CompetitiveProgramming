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


int solve_part_1(map<string, vector<string>>& mp) {
    int ans = 0;
    map<string, int> vis, dp;
    
    std::function<int(string)> dfs = [&](string u) -> int {
        debug(u);
        if (u == "out") {
            return dp[u] = 1;
        }
        vis[u]++;
        
        int cnt = 0;
        for (auto &v: mp[u]) {
            if (vis.find(v) == vis.end()) {
                cnt += dfs(v);
            } else {
                cnt += dp[v];
            }
        }
    
        debug(u, cnt);
        return dp[u] = cnt;
    };
    return dfs("you");
}


ll solve_part_2(map<string, vector<string>>& mp) {
    ll ans = 0;

    map<string, array<array<ll, 2>, 2>> visited, dp;

    std::function<ll(string, bool, bool)> dfs = [&](string u, bool has_fft, bool has_dac) -> ll {
        if (u == "fft") has_fft = true;
        if (u == "dac") has_dac = true;

        if (u == "out") {
            if (has_fft && has_dac) return dp[u][has_fft][has_dac] = 1LL;
            return dp[u][has_fft][has_dac] = 0;
        }

        visited[u][has_fft][has_dac] = 1;
        ll count = 0;

        for (auto &x: mp[u]) {
            if (!visited[x][has_fft][has_dac]) {
                count += dfs(x, has_fft, has_dac);
            } else {
                count += dp[x][has_fft][has_dac];
            }
        }
        debug(u, count);
        return dp[u][has_fft][has_dac] = count;
    };

    return dfs("svr", false, false);
}


void solve() {
    string s;

    int cnt = 0;
    map<string, vector<string>> mp;

    while (getline(cin, s)) {
        int idx = s.find(':');
        string t = s.substr(0, idx);
        string tmp = "";

        for (int i = idx + 2; i < s.size(); i++) {
            if (s[i] == ' ') {
                mp[t].push_back(tmp);
                tmp = "";
                i++;
            }
            tmp += s[i];
        }
        if (tmp != "") {
            mp[t].push_back(tmp);
        }
    }

    cout << "Part-2: " << solve_part_2(mp) << "\n"; 
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}