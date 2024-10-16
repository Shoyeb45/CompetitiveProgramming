#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<ll> a;
int bs(int l, int r, vector<ll> &a, ll target) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] == target) {
            return mid;
        }
        else if(a[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1] + a[i - 1];
    }
    // for(int i = 1; i <= n; i++) {
    //     // pref[i] += pref[i - 1] + a[i - 1];
    //     cout << pref[i] << ' ';
    // }
    // cout << "\n";


    ll mx = pref.back();
    int ans = n;

    for(int i = 1; i <= n; i++) {
        ll x = pref[i];

        int idx = -1;
        int k = 2;
        int temp = i, prevIdx = i;
        while(k * x <= mx) {
            idx = bs(i + 1, n, pref, k * x * 1LL);
            if(idx != -1) {
                temp = max(temp, idx - prevIdx);
                prevIdx = idx;
            }
            else {
                break;
            }
            k++;
        }
        if(idx == n) {
            ans = min(ans, temp);
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