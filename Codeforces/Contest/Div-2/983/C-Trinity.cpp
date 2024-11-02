#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;
bool bs(vector<int> &a, int x, int low) {
    int high = a.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] + x <= a.back()) {
            return true;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x : a) {
        cin >> x;
    }
    sort(range(a));

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += bs(a, a[i], i + 1);
    }
    reverse(range(a));
    int ans2 = 0;
    int t = a[n - 1] + a[n - 2];
    for(int i = 0; i < n; i++) {
        if(a[i] <= t) {
            ans2 = i + 1;
            break;
        }
    }
    cout << min(ans, ans2) << "\n";
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