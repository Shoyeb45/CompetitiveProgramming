#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
void solve() {
    cin >> n >> k;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> c;
    for(auto it: mp) {
        c.push_back(it.second);
    }

    sort(range(c));
    
    ll days = 0;
    ll curr = 0;
    ll left = 0;
    for(auto x: c) {
        cout << x << " ";
    }
    cout << "\n";
    for(int i = c.size() - 1; i >= left; i--) {
        curr += c[i];
        if(curr >= k) {
            days += curr / k;
            // rem = curr % k;
            if(curr % k > 0) {
                days++;
            }
            curr = 0;
            continue;
        }
        while(left < i && curr + c[left] <= k) {
            curr += c[left++];
        }
        days++;
        curr = 0;
    }

    
    cout << days << "\n";
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