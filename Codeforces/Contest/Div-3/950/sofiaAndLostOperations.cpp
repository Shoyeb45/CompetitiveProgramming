#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    loop(i, n) {
        cin >> a[i];
    }
    loop(i, n) {
        cin >> b[i];
    }
    int m;
    cin >> m;
    set<int> d;
    loop(i, m) {
        int x;
        cin >> x;
        d.insert(x);
    }
    vector<int> c;

    loop(i, n) {
        if(a[i] != b[i]) {
            c.push_back(b[i]);
        }
    }
    if(m < c.size()) {
        cout << "NO\n";
        return;
    }

    sort(c.begin(), c.end());
    vector<int> new_d;
    // map<int, int> mp;
    // loop(i, m) 
    //     mp[d[i]]++;
    // for(auto it : mp) {
    //     if(it.second == 1) {
    //         new_d.push_back(it.first);
    //     }
    // }
    // loop(i, new_d.size()) {
    //     cout << new_d[i] << ' ';
    // }
    // cout << "....\n" ;
    // loop(i, c.size()) {
    //     if(!binary_search(d.begin(), d.end(), c[i])) {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    int cnt = 0;
    for(auto it = d.begin(); it != d.end(); it++) {
        if(binary_search(c.begin(), c.end(), *it))
            cnt++;
    }
    // loop(i, new_d.size()) {
    //     if(binary_search(c.begin(), c.end(), new_d[i]))
    //         cnt++;
    // }
    if(cnt == c.size())
        cout << "YES\n";
    else 
        cout << "NO\n";
    // cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
