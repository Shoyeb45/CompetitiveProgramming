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

tuple<string, vector<vector<int>>, vector<int>> parse_input(string &s) {
    int idx = s.find(']');
    string inidcator_light = s.substr(1, idx - 1);
    
    int n = s.size();
    int i;

    vector<vector<int>> switches;

    for (i = 0; i < n; i++) {
        if (s[i] == '{') 
            break;
        if (s[i] == '(') {
            i++;
            vector<int> tmp;
            string num = "";
            while (i < n) {
                if (s[i] == ')') {
                    tmp.push_back(stoi(num));
                    break;
                }
                
                if (s[i] == ',') {
                    tmp.push_back(stoi(num));
                    num = "";
                    i++;
                    continue;
                }
                num += s[i];
                i++;
            }
            if (!tmp.empty()) switches.push_back(tmp);
        }
    }
    vector<int> jolt;
    string num = "";
    i++;
    for (; i < n; i++) {
        if (s[i] == ',' || s[i] == '}') {
            jolt.push_back(stoi(num));
            num = "";
            continue;
        }
        num += s[i];
    }

    return make_tuple(inidcator_light, switches, jolt);
}

ll solve_part_1(string &light_state, vector<vector<int>>& switches) {
    int n = light_state.size();
    int m = switches.size();

    vector<int> valid_idx;
    for (int i = 0; i < n; i++) {
        if (light_state[i] == '#') valid_idx.push_back(i);
    }
    debug(valid_idx);
    ll ans = INT_MAX;
    int iter = (1 << m);
    
    for (int mask = 1; mask < iter; mask++) {
        int bits = (int) log2(mask) + 1;
        ll cnt = 0;
        map<int, int> mp;
        debug(mask);
        for (int i = 0; i < bits; i++) {
            if (((1 << i) & mask)) {
                cnt++;
                debug(switches[i]);
                for (auto x: switches[i]) {
                    mp[x]++;
                }
            }
        }
        debug(mp);
        vector<int> tmp;
        for (auto& [ele, freq]: mp) {
            if (freq % 2 == 1) tmp.push_back(ele);
        }
        debug(tmp);
        if (tmp == valid_idx) {
            ans = min(ans, cnt);
        }
    }

    debug(ans);
    return ans;
}

bool check(set<int> &t, set<int> &invalid_idxs) {
    for (auto &x: invalid_idxs) {
        if (t.count(x)) {
            return false;
        }
    }
    return true;
}

ll part_2_util(vector<set<int>>& switches, vector<int>& jolts, set<int>& invalid, int cnt) {
    int n = jolts.size();
    debug("----");
    // last
    if (n == cnt) {
        return 0;
    }
    debug(jolts);
    debug(invalid);
    int mn = *min_element(range(jolts));
    int idx;
    for (int i = 0; i < n; i++) 
        if (jolts[i] == mn) {
            idx = i;
            break;
        }
    
    ll cost = jolts[idx];
    debug(cost, idx);
    ll ans = INT_MAX;

    for (auto& s: switches) {
        if (s.count(idx) && check(s, invalid)) {
            // change jolts
            // add invalid indices
            vector<int> indices;
            debug(s);
            for (int i = 0; i < n; i++) {
                if (s.count(i)) {
                    if (jolts[i] == INT_MAX) continue;

                    jolts[i] -= cost;
                    if (jolts[i] == 0) {
                        jolts[i] = INT_MAX;
                    }
                    indices.push_back(i);
                }
            }
            
            for (int i: indices) {
                if (jolts[i] == INT_MAX)
                    invalid.insert(i);
            }
            ans = min(ans, part_2_util(switches, jolts, invalid, cnt + 1));
            
            for (int i : indices) {
                if (jolts[i] == INT_MAX) {
                    invalid.erase(i);
                }
            }
            // undo the changes
            for (int i : indices) {
                if (jolts[i] == INT_MAX) jolts[i] = 0;
                jolts[i] += cost;
            }
        }
    }
    
    debug(cost, ans);
    return cost + (ans == INT_MAX ? 0: ans);
}

ll solve_part_2(vector<vector<int>> &switches, vector<int> &jolts) {
    int n = jolts.size(), m = switches.size();

    vector<set<int>> swit;
    for (auto& x: switches) 
        swit.push_back(set<int>(range(x)));

    set<int> invalid;

    ll ans = part_2_util(swit, jolts, invalid, 0);
    cout << ans << " ";
    return ans;
}

void solve() {
    string s;

    ll ans = 0;
    while (getline(cin, s)) {
        auto [light_state, switches, jolts] = parse_input(s);
        // ans += solve_part_1(light_state, switches);
        ans += solve_part_2(switches, jolts);
    }

    // cout << "Part-1 " << ans << "\n";
    cout << "\nPart-2: " << ans << "\n";
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