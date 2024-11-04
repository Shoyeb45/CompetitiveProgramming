#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<ll> a, h;

void solve() {
    cin >> n >> k;
    a.resize(n), h.resize(n);

    for(auto &x : a) {
        cin >> x;
    }    
    for(auto &x : h) {
        cin >> x;
    }    


    ll sum = 0; 
    int ans = 0; 
    int l = 0; 

    for(int r = 0; r < n; r++) {
        sum += a[r]; 
        
        
        while (l < r && h[r - 1] % h[r] != 0) {
            sum -= a[l]; 
            l++; 
        }

        
        while (sum > k) {
            sum -= a[l]; 
            l++;
        }

        
        ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
}
    // ll sum = a.front();
    // int ans = sum < k;
    // int div = 0;
    // for(int r = 1, l = 0; r < n; r++) {
    //     sum += a[r], div += h[r - 1] % h[r];    
    //     // cout << " d f " << h[l - 1] % h[l] << "\n"; 
    //     // debug("div", div);
    //     debug("sum before", sum);
    //     debug("l before", l, "r before", r);
    //     while(l + 1 < n && div != 0) {
    //         sum -= a[l];
    //         div -= h[l] % h[l + 1]; 
    //     }

    //     while(l < n && sum > k) {
    //         sum -= a[l];
    //         // div -= h[l - 1] % h[l++]; 
    //     }
    //     debug("sum", sum);
    //     debug("l", l, "r", r);
    //     ans = max(ans, r - l + 1);
    // }



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