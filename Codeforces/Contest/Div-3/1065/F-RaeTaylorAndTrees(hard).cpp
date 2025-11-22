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


class DisjointSetsUnion {
    private:
        vector<int> parent;
        vector<int> height;
    
    public: 
        DisjointSetsUnion(int n) {
            parent.resize(n), height.resize(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                height[i] = 0;
            }
        }
    

        void unite(int x, int y) {
            int root1 = get(x), root2 = get(y);

            if(height[root1] > height[root2]) {
                parent[root2] = root1;
                height[root1] = max(height[root1], height[root2] + 1);
            }
            else {
                parent[root1] = root2;
                height[root2] = max(height[root2], height[root1] + 1);
            }
        }

        int get(int x) {
            if(parent[x] != x) {
                return parent[x] = get(parent[x]);
            }
            return parent[x];
        }

        bool isConnected(int x, int y) {
            return get(x) == get(y);
        }

        void display() {
            cout << "Parents: " << "\n";
            for(auto x: parent) {
                cout << x << " ";
            }
            cout << "\n";

            cout << "Heights: " << "\n";
            for(auto x: height) {
                cout << x << " ";
            }
            cout << "\n";
        }
};


void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    DisjointSetsUnion dsu(n);

    stack<int> st;
    vector<pair<int, int>> vp;

    for (int i = 0; i < n; i++) {
        int curr_min = p[i];

        while (!st.empty() && st.top() < p[i]) {
            int r1 = dsu.get(st.top() - 1), r2 = dsu.get(p[i] - 1);
            
            if (r1 != r2) {
                dsu.unite(st.top() - 1, p[i] - 1);
                vp.push_back(make_pair(st.top(), p[i]));
            }

            curr_min = min(st.top(), curr_min);
            st.pop();
        }
        st.push(curr_min);
    }

    if (vp.size() < n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto x: vp) 
        cout << x.first << " " << x.second << "\n";
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