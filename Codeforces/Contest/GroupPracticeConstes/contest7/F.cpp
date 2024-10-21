#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
int ask(string msg, int i, int j) {
    cout << msg << " " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

int getVal(int i, int j) {
    int _and = ask("and", i, j);
    int _or = ask("or", i, j);
    return _and + (_or);
}

void solve() {
    cin >> n >> k;
    vector<int> ans;
    
    int x = getVal(1, 2);
    int y = getVal(2, 3);
    int z = getVal(1, 3);

    ans.push_back((x - y + z) / 2);
    ans.push_back((x + y - z) / 2);
    ans.push_back((z - x + y) / 2);
    for(int i = 4; i <= n; i++) {
        int temp = getVal(i, i - 1);
        ans.push_back(temp - ans[i - 2]);
    }
    // for(auto x: ans) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    sort(range(ans));

    cout << "finish " << ans[--k] << endl;
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    // #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}