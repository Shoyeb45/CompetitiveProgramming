#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

class DisjointSetsUnion {
  private:
    vector<int> parent;
    vector<int> height;

  public:
    DisjointSetsUnion(int n) {
        parent.resize(n), height.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            height[i] = 0;
        }
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y)
            return;

        if (height[x] < height[y])
            swap(x, y);
        parent[y] = x;

        if (height[x] == height[y])
            height[x]++;
    }

    int get(int x) {
        if (parent[x] != x) {
            return parent[x] = get(parent[x]);
        }
        return parent[x];
    }

    bool isConnected(int x, int y) {
        return get(x) == get(y);
    }
};

ll find_sq(ll a) {
    return (ll)a * a;
}

ll find_dist(vector<ll> &a1, vector<ll> &a2) {
    ll dis = find_sq(a1[0] - a2[0]) + find_sq(a1[1] - a2[1]) + find_sq(a1[2] - a2[2]);
    return dis;
}

vector<vector<ll>> take_input() {
    vector<vector<ll>> a;
    string s;
    while (cin >> s) {
        int idx = s.find(',');
        int idx2 = s.find(',', idx + 1);
        vector<ll> tmp;

        tmp.push_back(stoll(s.substr(0, idx)));
        tmp.push_back(stoll(s.substr(idx + 1, idx2 - idx - 1)));
        tmp.push_back(stoll(s.substr(idx2 + 1)));

        a.push_back(tmp);
    }
    return a;
}

void solve_part_1() {
    vector<vector<ll>> a = take_input();


    int n = a.size();
    set<pair<ll, pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dis = find_dist(a[i], a[j]);
            st.insert(make_pair(dis, make_pair(i, j)));
        }
    }

    DisjointSetsUnion dsu(n);
    int edges_taken = 0;
    const int NEED = 1000;

    for (auto &x : st) {
        if (edges_taken == NEED)
            break;
        edges_taken++;  // **count this edge among the 1000 shortest**
        int i = x.second.first, j = x.second.second;

        if (dsu.get(i) != dsu.get(j)) {
            dsu.unite(i, j);
        }
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[dsu.get(i)]++;
    }

    vector<int> sizes;
    for (auto &p : mp) {
        sizes.push_back(p.second);
        cout << p.second << "\n";
    }
    sort(rrange(sizes));

    // guard: if less than 3 components exist, treat missing ones as size 1
    while (sizes.size() < 3)
        sizes.push_back(1);

    ll ans = 1;
    ans *= sizes[0];
    ans *= sizes[1];
    ans *= sizes[2];
    cout << ans << "\n";
}



void solve_part_2() {
    vector<vector<ll>> a = take_input();

    int n = a.size();
    vector<tuple<ll, int, int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            st.emplace_back(find_dist(a[i], a[j]), i, j);
        }
    }


    sort(range(st));
    DisjointSetsUnion dsu(n);

    ll last_x, last_y;

    for (auto [_, x, y]: st) {
        if (dsu.get(x) != dsu.get(y)) {
            dsu.unite(x, y);
            last_x = a[x][0], last_y = a[y][0];
        }
    }
    cout << (ll) last_x * last_y << "\n";
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

    for (int i = 1; i <= tt; i++) {
        solve_part_2();
    }

    return 0;
}
