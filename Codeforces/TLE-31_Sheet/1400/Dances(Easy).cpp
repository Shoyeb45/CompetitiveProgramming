#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
vector<int> a, b;

bool check(int mid) {
    int i = n - mid, j = mid;
    while(i >= 0 && j < n) {
        if(a[i] >= b[j]) {
            return false;
        }
        i--, j++;
    }
    return true;
}
void solve() {
    cin >> n >> m;
    a.resize(n), b.resize(n);
    a[0] = 1;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for(auto &x: b) {
        cin >> x;
    }
    sort(range(a)), sort(range(b));
    // for(auto x: a) {
    //     cout << x << " ";
    // } cout << endl;
    // for(auto x: b) {
    //     cout << x << " ";
    // } cout << endl;

    int low = 0, high = n, ans = -1;
    while(low <= high) {
        int mid = (high + low) / 2;
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    } 
    cout << ans << "\n";

}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}