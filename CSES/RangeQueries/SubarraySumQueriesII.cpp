#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class Node {
public:
    ll maxSubarraySum, maxPrefixSum, maxSuffixSum, sum; 

    Node(ll maxSubarraySum, ll maxPrefixSum, ll maxSuffixSum, ll sum) {
        this->maxSubarraySum = maxSubarraySum;
        this->maxPrefixSum = maxPrefixSum;
        this->maxSuffixSum = maxSuffixSum;
        this->sum = sum;
    }
};


class SegmentTree {
public:
    int n;
    vector<Node*> tree;


    SegmentTree(vector<ll> &a) {
        this -> n = a.size();
        tree.resize(4 * n + 1);
        utilBuild(a, 0, n - 1, 0);
    }

    ll query(int l, int r) {
        Node* res = queryUtil(0, n - 1, 0, l, r);
        return res -> maxSubarraySum;
    }

private:
    void utilBuild(vector<ll> &a, int l, int r, int i) {
        if (l == r) {
            tree[i] = new Node(a[l], a[l], a[l], a[l]);
            // tree[i] -> maxPrefixSum = tree[i] -> maxSubarraySum = tree[i] -> maxSuffixSum = tree[i] -> sum = a[l]; 
            return;
        }

        int m = (l + r) / 2, left_idx = (2 * i) + 1, right_idx = (2 * i) + 2;

        utilBuild(a, l, m, left_idx);
        utilBuild(a, m + 1, r, right_idx);

        Node* left = tree[left_idx];
        Node* right = tree[right_idx];

        tree[i] = new Node(0, 0, 0, 0);
        tree[i] -> maxSubarraySum = max({
            left -> maxSubarraySum, 
            right -> maxSubarraySum, 
            left -> maxSuffixSum + right -> maxPrefixSum
        });
        tree[i] -> sum = left -> sum + right -> sum;
        tree[i] -> maxPrefixSum = max(left -> maxPrefixSum, left -> sum + right -> maxPrefixSum);
        tree[i] -> maxSuffixSum = max(right -> maxSuffixSum, right -> sum + left -> maxSuffixSum);
    }

    Node* queryUtil(int seg_l, int seg_r, int tree_i, int q_l, int q_r) {
        if (q_l <= seg_l && seg_r <= q_r) {
            return tree[tree_i];
        } else if (q_r < seg_l || seg_r < q_l) {
            return nullptr;
        }

        int m = (seg_l + seg_r) / 2, left_idx = (2 * tree_i) + 1, right_idx = (2 * tree_i) + 2;
        Node* left = queryUtil(seg_l, m, left_idx, q_l, q_r);
        Node* right = queryUtil(m + 1, seg_r, right_idx, q_l, q_r);

        if (!left) {
            return right;
        }

        if (!right) {
            return left;
        }
        

        Node* res = new Node(0, 0, 0, 0);
        res -> sum = left->sum + right->sum;
        res -> maxPrefixSum = max(left -> maxPrefixSum, left -> sum + right -> maxPrefixSum);
        res -> maxSuffixSum = max(right -> maxSuffixSum, right -> sum + left -> maxSuffixSum);
        res -> maxSubarraySum = max({
            left -> maxSubarraySum,
            right -> maxSubarraySum,
            left -> maxSuffixSum + right -> maxPrefixSum
        });
        return res;
    }
    
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }    
    
    vector<pair<int, int>> queries;
    while (q--) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    SegmentTree sg(a);


    for (auto que: queries) {
        ll res = sg.query(que.first - 1, que.second - 1);
        cout << (res < 0? 0: res) << "\n";
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