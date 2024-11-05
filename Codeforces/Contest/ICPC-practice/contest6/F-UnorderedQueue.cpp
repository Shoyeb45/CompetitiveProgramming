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

void solve() {
    cin >> n;
    a.resize(n);
    map<int, ll> mp;
    for(auto &x: a) {
        cin >> x;
        mp[x]++;
    }
    if(n == 1) {
        cout << 1 << "\n";
        return;
    }
    if(n == 2) {
        if(mp.size() == 1) {
            cout << 2 << "\n";
        }
        else {
            cout << 1 << "\n"; 
        }
        return;
    }

    ll ans = 0;
   
    vector<ll> vp;

    for(auto it: mp) {
        vp.push_back(it.second);
    }
    if(vp.size() == 1) {
        cout << vp[0] << "\n";
        return;
    }
    else if(vp.size() == 2) {
        cout << vp[0] - 1 + vp[1] << "\n";
        return;
    }
    else if(vp.size() == 3) {
        ll ans = vp[0] + vp[2];
        if(vp[1] > 2) {
            ans += vp[1] - 2;
        }
        cout << ans << "\n";
        return;
    } 
    swap(vp[0], vp[1]);
    ans += vp[0];

    for(int i = 1; i < vp.size() - 1; i++) {
        ans += vp[i] - 1;
    }
    ans += vp.back();

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