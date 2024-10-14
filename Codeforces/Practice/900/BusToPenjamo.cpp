#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, r;
vector<int> a;
void solve() {
    cin >> n >> r;
    a.resize(n);
    int happy = 0;
    for(auto &x: a) {
        cin >> x;
        happy += (x / 2) * 2;
        r -= x / 2;
        x -= (x / 2) * 2;
    }

    int rem = 0;
    for(auto x: a) {
        rem += x;
    }

    if(rem > r) {
        if(rem != 2 * r) {
            happy += (rem / r) * r - (rem % r);
        }

    }
    else {
        happy += rem;
    }

    cout << happy << "\n";

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