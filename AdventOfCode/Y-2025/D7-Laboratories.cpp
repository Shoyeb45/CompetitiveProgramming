#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve_part_1() {
    vector<string> a;
    string s;
    while (cin >> s) {
        a.push_back(s);
    }

    set<pair<int, int> > q;

    int n = a.size(), m = a[0].size();

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                q.insert(make_pair(i + 1, j));
                a[i + 1][j] = '|';
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    int ans = 0;
    while (!q.empty()) {
        auto p = *q.begin();
        int x = p.first, y = p.second;
        q.erase(q.begin());

        if (x + 1 < n && a[x + 1][y] == '^') {
            // split
            ans++;
            int i = x + 1, j = y - 1;
            if (i < n && j >= 0) {
                a[i][j] = '|';
                q.insert(make_pair(i, j));
            } 
            j = y + 1;
            if (i < n && j < m) {
                a[i][j] = '|';
                q.insert(make_pair(i, j));
            }
            continue;
        }
        if (x + 1 < n) {
            a[x + 1][y] = '|';
            q.insert(make_pair(x + 1, y));
        }
    }

    cout << ans << "\n";
    for (auto x: a) {
        cout << x << "\n";
    }
}   


void solve_part_2() {
    string s;
    vector<string> a;

    while (cin >> s) 
        a.push_back(s);

    int n = a.size(), m = a[0].size();

    int x, y;

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                a[i + 1][j] = '|';
                ok = true;
                x = i + 1, y = j;
                break;
            }
        }
        if (ok) break;
    }

    vector<vector<ll> > dp(n, vector<ll> (m, -1));
    
    std::function<ll(int, int)> dfs = [&](int x, int y) -> ll {
        if (x == n - 1)
            return 1;

        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        ll ans = 0;

        if (a[x + 1][y] == '^') {
            // two possibilities
            int i = x + 1, j = y - 1;
            if (j >= 0) {
                ans += dfs(i, j);
            }
            j = y + 1;
            if (j < m) {
                ans += dfs(i, j);
            }
            return dp[x][y] = ans;
        } 

        return dp[x][y] = dfs(x + 1, y);
    };

    cout << dfs(x, y) << "\n";

}
int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif

    solve_part_2();

    return 0;
}