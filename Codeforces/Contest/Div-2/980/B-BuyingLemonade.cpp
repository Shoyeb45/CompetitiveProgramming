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
vector<ll> a;
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    sort(range(a));
    
    ll cans = 0, mnButton = 0, prev = 0;
    for(int i = 0; i < n; i++) {    
        
        ll tempCan = (a[i] - prev) * (n - i);
        if(tempCan >= k - cans) {
            cout << mnButton + (k - cans) << "\n";
            return;
        }
        else {
            mnButton += tempCan + 1;
            cans += tempCan;
        }
        prev = a[i];
    } 
    cout << mnButton << "\n";
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