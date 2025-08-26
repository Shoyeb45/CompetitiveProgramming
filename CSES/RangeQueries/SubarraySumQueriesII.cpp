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
    int maxSubarraySum, maxPrefixSum, maxSuffixSum, sum; 

    Node(int maxSubarraySum, int maxPrefixSum, int maxSuffixSum, int sum) {
        this->maxSubarraySum = maxSubarraySum;
        this->maxPrefixSum = maxPrefixSum;
        this->maxSuffixSum = maxSuffixSum;
        this->sum = sum;
    }
};


class SegmentTree {
public:
    int n;
    vector<Node> tree;

    SegmentTree(int n) {
        this.n = n;
        tree.resize(4 * n + 1);
    }

    void build(vector<int> &a) {

    }
private:
    void utilBuild(vector<int> &a, int l, int r, int i) {
        if (l == r) {
            tree[i].maxPrefixSum = tree[i].maxSubarraySum = tree[i].maxSuffixSum = tree[i].sum = a[l]; 
        }

        int m = (l + r) / 2;

        utilBuild(a, l, m, 2 * i + 1);
        utilBuild(a, m + 1, r, 2 * i + 2);

        Node left = tree[2 * i + 1];
        Node right = tree[2 * i + 2];

        tree[i].maxSubarraySum = max({left.maxSubarraySum, })
    }
};
void solve() {
    
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