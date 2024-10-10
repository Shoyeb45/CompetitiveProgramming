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

    int zeroes = 0, neg = 0;
    for(auto &x: a) {
        cin >> x;
        zeroes += (x == 0);
        neg += (x < 0);
    }
    ll sum = 0;  
    if((zeroes > 0) || (neg % 2 == 0)) {
        for(auto x: a) {
            if(x < 0) {
                sum += (-x);
            } 
            else {
                sum += x;
            }
        }
    }
    else if((neg & 1) == 1) {   
        ll mn = INT_MAX;
        for(auto x: a) {
            if(x < 0) {
                mn = min(mn, -x);
            }
            else {
                mn = min(mn, x);
            }
        }

        for(auto x: a) {
            if(x < 0) {
                sum += (-x);
            } 
            else {
                sum += x;
            }
        }
        sum -= 2 * mn;
    }

    cout << sum << "\n";
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