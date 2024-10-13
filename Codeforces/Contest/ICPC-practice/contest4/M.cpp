#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;
vector<ll> a; 

bool check(ll mid) {
    ll currSum = 0, seg = 1;
    for(auto x: a) {
        if(currSum + x > mid) {
            seg++;
            currSum = x;
            if(seg > m) {
                return false;
            }
        }
        else {
            currSum += x;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll low = *max_element(range(a)), high = accumulate(range(a), 0);
    while(low < high) {
        ll mid = low + (high - low) / 2;
        if(check(mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << (high + k - 1) / k << "\n";
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