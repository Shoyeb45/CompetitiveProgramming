#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<pair<ll, ll>> vp;
int p;
set<ll> pegs; 

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    vector<ll> ans;

    sort(range(vp), [](pair<ll,ll>& a, pair<ll,ll>& b){
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    cin >> p;
    for (int i = 0; i < p; i++) {
        ll x; 
        cin >> x;
        pegs.insert(x);
    }
    unordered_map<ll, int> occupied;

    for (auto x: vp) {
        int l = x.first, r = x.second;
        
        vector<ll> pre;
        auto it_l = pegs.lower_bound(l);
        while (it_l != pegs.end() && *it_l <= r) {
            pre.push_back(*it_l);
            it_l++;
        }
        
        ll position = r;
        if (pre.size() > 2) {
            cout << "impossible\n";
            return;
        }

        int need = 2 - (int) pre.size();
        while (need > 0) {
            if (position < l) {
                cout << "impossible\n";
                return;
            }

            if (pegs.find(position) == pegs.end() && occupied.find(position) == occupied.end()) {
                pegs.insert(position);
                ans.push_back(position);
                --need;
            }
            --position;
        }
        occupied[r]++;
    }
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}