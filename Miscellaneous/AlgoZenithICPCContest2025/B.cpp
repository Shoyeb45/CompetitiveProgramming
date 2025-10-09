#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; 1LL * i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

// ---------- Segment Tree ----------
struct SegTree {
    int n;
    vector<vector<int>> tree;
    vector<int> arr;

    SegTree(vector<int>& a) {
        arr = a;
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            if (arr[l] == 1 || isPrime(arr[l]))
                tree[node] = {l};
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        merge(tree[node * 2].begin(), tree[node * 2].end(),
              tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
              back_inserter(tree[node]));
    }

    int get(int i) {
        return arr[i];
    }

    // ---------- Query indices in range ----------
    vector<int> query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {};
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        auto left = query(node * 2, l, mid, ql, qr);
        auto right = query(node * 2 + 1, mid + 1, r, ql, qr);
        vector<int> res;
        merge(left.begin(), left.end(), right.begin(), right.end(),
              back_inserter(res));
        return res;
    }

    vector<int> query(int l, int r) { return query(1, 0, n - 1, l, r); }

    // ---------- Point update ----------
    void update(int node, int l, int r, int idx, int newVal) {
        bool wasPrime = (arr[idx] == 1 || isPrime(arr[idx]));
        bool isNowPrime = (newVal == 1 || isPrime(newVal));

        // no change in primality status
        if (wasPrime == isNowPrime && arr[idx] == newVal) return;

        arr[idx] = newVal;

        // Update this node’s vector
        auto& vec = tree[node];
        auto it = lower_bound(vec.begin(), vec.end(), idx);
        if (wasPrime && it != vec.end() && *it == idx)
            vec.erase(it);
        if (isNowPrime)
            vec.insert(lower_bound(vec.begin(), vec.end(), idx), idx);

        if (l == r) return;

        int mid = (l + r) / 2;
        if (idx <= mid) update(node * 2, l, mid, idx, newVal);
        else update(node * 2 + 1, mid + 1, r, idx, newVal);
    }

    void update(int idx, int newVal) { update(1, 0, n - 1, idx, newVal); }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    SegTree sg(a);
    
    
    while (q--) {
        int t, b, c;
        cin >> t >> b >> c;
        b--;
        if (t == 1) {
            sg.update(b, c);
        } else {
            c--;
            vector<int> indices = sg.query(b, c);
            int len = c - b + 1;
            ll total = (1LL * len * (len + 1)) / 2;
            ll none = 0;

            int k = indices.size();
            debug(indices);
            for (int i = 0; i < indices.size(); i++) {
                if (i == 0) {
                    none += 1LL * (indices[i] - b + 1) * (i + 1 >= k ? c - indices[i] + 1: (indices[i + 1]) - indices[i]) - (sg.get(indices[i]) != 1); 
                } else if (i == indices.size() - 1) {
                    none += 1LL * (i - 1 < 0 ? 1 : (indices[i] - indices[i - 1])) * (c - indices[i] + 1) - (sg.get(indices[i]) != 1);
                } else {
                    none += 1LL * (indices[i] - indices[i - 1]) * (indices[i + 1] - indices[i]) - (sg.get(indices[i]) != 1);
                }
            }
            cout << total - none << "\n";
        }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
