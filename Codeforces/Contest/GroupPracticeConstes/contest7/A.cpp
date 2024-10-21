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
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    if(n == 1) {
        cout << 0 << "\n";
        return;
    }

    ll prev = a.front(), sum = a[1];
    int i = 1; 
    ll ans = 0;
    while(i < n) {
        if(a[i] >= prev) {
            prev = a[i++];
            continue;
        }
        sum = 0;
        int temp = 0;
            // cout << "sfas: ";
        while(i < n && sum < prev) {
            // cout << a[i] << " ";
            temp++, sum += a[i++];
        }
        // cout<<endl;
        prev = sum;
        ans += temp - 1;
    } 
    if(prev == a.back()) {
        ans++;
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