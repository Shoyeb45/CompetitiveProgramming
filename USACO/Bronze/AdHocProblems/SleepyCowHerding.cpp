#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<int> a(3, 0);
void solve() {
    cin >> a[0] >> a[1] >> a[2];
    sort(range(a));

    if(a[0] + 1 == a[1] && a[1] + 1 == a[2]) {
        cout << "0\n0\n";   
        return;
    }

    int mn = 1;
    
    if(abs(a[0] - a[1]) > 2 && abs(a[1] - a[2]) > 2) {
        mn++;
    }
    else if(a[1] - a[0] == 1 || a[2] - a[1] == 1) {
        mn++;
    }

    int mx = max(a[1] - a[0] - 1, a[2] - a[1] - 1);

    cout << mn << "\n" << mx << "\n";
}

int main() {
    NFS
        freopen("herding.in", "r", stdin);
        freopen("herding.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}