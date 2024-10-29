#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a, b, c;
vector<int> findThreeMax(vector<int> &a) {
    vector<pair<int,int>> aa;
    for(int i = 0; i < a.size(); i++) {
        aa.push_back(make_pair(a[i], i));
    }
    sort(range(aa));

    return {aa[n - 1].second, aa[n - 2].second, aa[n - 3].second};

}
void solve() {
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }
    for(auto &x: c) {
        cin >> x;
    }

    ll ans1 = 0, ans2 = 0, ans3 = 0;

    vector<int> idxA = findThreeMax(a), idxB = findThreeMax(b), idxC = findThreeMax(c);

    ll ans = 0;

    for(int i: idxA) {
        ll temp = a[i];
        for(int j: idxB) {
            if(j == i) {
                continue;
            }
            else {
                temp += b[j];
                for(int k: idxC) {
                    if(k != j && k != i) {
                        temp += c[k];
                        ans = max(ans, temp);
                        temp -= c[k];
                    }
                }
                temp -= b[j];
            }
        }
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

    while (tt--) {
        solve();
    }

    return 0;
}