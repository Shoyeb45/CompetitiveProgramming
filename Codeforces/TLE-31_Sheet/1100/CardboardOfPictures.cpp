#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll x;
vector<ll> a;
ll f(ll mid) {
    ll b = 2 * 1LL * mid;
    // debug("mid",mid);
    ll sum = 0;
    for(auto y: a) {
        sum += 1LL * (y + b) * (y + b);
        if(sum > x) {
            return sum;
        }
    }
    // debug("iSum", sum);
    // debug("s", sum);
    return sum;
}

void solve() {
    cin >> n >> x;
    a.resize(n);
    for(auto &X: a) {
        cin >> X;
    }
    ll low = 0, high = 1e10
    ;
    ll ans = 0;
    // cout << sum << "\n";

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll temp = f(mid);
        if(temp == x) {
            ans = mid;
            break;
        } 
        else if(temp > x) {
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