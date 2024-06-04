#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool c1(vector<pair<int, int>> &vp, int target, int k) {
    loop(i, k+1) {
        if(vp[i].first == target)
            return true;
    }
    return false;
}

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    f--;
    k--;
    vector<pair<int, int>> vp;
    loop(i, n) {
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    int target = vp[f].first;
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    // for(auto it: vp) {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
    
    int cnt = 0;
    // cout << target << '\n';
    for(auto it: vp) 
        if(it.first == target)
            cnt++;
    
    if(cnt == 1) {
        loop(i, n) {
            if(vp[i].first == target && i <= k) {
                cout << "YES\n";
                return;
            }
        } 
    } else if(cnt > 1) {
        // bool c1 = false;
        // for(int i = 0; i <= k; i++) {
        //     if(vp[i].first != target) {
        //         c1 = true;
        //     } else {
        //         c1 = false;
        //         break;
        //     }
        // }
        int cnt2 = 0;
        for(int i = 0; i <= k ;i++) {
            if(vp[i].first == target) {
                cnt2++;
            }
        }
        if(!c1(vp, target, k)) {
            cout << "NO\n";
            return;
        }
        loop(i, n) {
            if(vp[i].first == target && i > k) {
                cout << "MAYBE\n";
                return;
            }
        }
        if(cnt2 <= k + 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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
