#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, x;
ll getMex(map<ll, ll> &mp) {
    ll ans = -1;
    for(auto x: mp) {
        if(ans + 1 == x.first) {
            ans = x.first;
        }
    }
    return ans + 1;
}
void solve() {
    cin >> n >> x;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }

    ll mex = getMex(mp);

    for(auto &it: mp) {
        if(it.first + x > mex) {
            break;
        }
        if(it.second > 1) {
            while(it.second > 1) {
                ll rem = (mex - it.first) / x;
                if(it.first + 1LL * rem * x == mex) {
                    mp[mex]++;
                    mex++;

                    while(mp.find(mex) != mp.end()) {
                        mex++;
                    }
                }
                else if(rem != 0) {
                    mp[it.first + 1LL * rem * x]++;
                }
                it.second--;
            }
        }
    }
        cout << (ll)mex << "\n";
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