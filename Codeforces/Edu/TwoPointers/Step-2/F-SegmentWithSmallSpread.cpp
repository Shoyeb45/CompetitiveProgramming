#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n;
ll k;
map<ll, int> mp;
vector<ll> a;

bool good(ll mn, ll mx) {
    return mp.empty()? false: mx - mn <= k;
}

void add(int index) {
    mp[a[index]]++;
}

void update(ll &mn, ll &mx) {
    if(!mp.empty()) {
        mn = mp.begin() -> first, mx = mp.rbegin() -> first;
    }
}

ll sumOfN(ll x) {
    return (1LL * x * (x + 1)) / 2;
}

void remove(int index) {
    mp[a[index]]--;
    if(mp[a[index]] == 0) {
        mp.erase(mp.find(a[index]));
    }
}

void printmp(string msg) {
    cout << msg << "\n";
    for(auto &x: mp) {
        debug("key", x.first, "value", x.second);
    }
}
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }     

    int left = 0;
    ll ans = 0, mn = 0, mx = 0;

    for(int right = 0; right < n; right++) {
        add(right);
        printmp("Add " + to_string(right));
        update(mn, mx);
        debug("mn", mn, "mx", mx);
        while(left < n && !good(mn, mx)) {
            remove(left++);
            printmp("remove " + to_string(left - 1));
            update(mn, mx);
            debug("mn", mn, "mx", mx);
        }
        ans += right - left + 1;
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
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}