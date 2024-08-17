#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;

bool check(vector<int> &a, int x) {
    loop(i, a.size()) {
        if(abs(a[i] - x) > min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]))) {
            return false;
        }
    }
    return true;
}


void solve() {
    cin >> n;
    vector<int> a(n + 1);
    unordered_map<int, int> mp;
    a[0] = 1e6;
    loop(i, n) {
        cin >> a[i + 1];
        mp[a[i + 1]]++;
    }

    int mn = a[1], mx = a[n];

    for(int i = mn + 1; i <= mx + 1; i++) {
        if(mp.find(i) == mp.end() && check(a, i)) {
            cout << "YES\n";
            return;
        }
    } 
    cout << "NO\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
