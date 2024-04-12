#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// vector<pair<ll, int>> elements(vector<ll> &x, ll target) {
//     vector<pair<ll, int>> ans;
//     for(int i = 0; i < x.size(); i++) {
//         if(x[i] == target)  ans.push_back({x[i], i});
//     }
//     return ans;
// } 


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        // sort(x.begin(), x.end());

        // vector<pair<ll, int>> vp = elements(x, a - b);
        // vector<vector<int>> vv;

        // int i = 0;
        // while(i < n - 1) {
        //     ll sum = 0;
        //     sum += x[i];
        //     vector<int> h = {i};
        
        //     for(int j = i + 1; j < n; j++) {
        //         sum += x[j];
        //         if(sum < a)    h.push_back(j);
        //         else {
        //             i = j;
        //             break;
        //         }
        //     }
        //     if(h.size() != 1)   vv.push_back(h);
        // }  

        // ll seconds = 0, c = b;
        // if(vp.size() != 0) {
        //     for(auto & pair : vp) {
        //         c += pair.first;
        //         c = min(a, c);
        //         c--;
        //         seconds += c;
        //         c = 1;
        //         x[pair.second] = 0;
        //     }
        // }

        // if(vv.size() != 0) {
        //     for(auto & v : vv) {
        //         ll sum = 0;
        //         for(int & i : v) {
        //             sum += x[i];
        //             x[i] = 0;
        //         }
        //         c += sum;
        //         c = min(a, c);
        //         c--;
        //         seconds += c;
        //         c = 1;
        //     }
        // }

        // for(ll & i : x) {
        //     if(i != 0) {
        //         c += i;
        //         c = min(a, c);
        //         c--;
        //         seconds += c;
        //         c = 1;
        //     }
        // }

        // cout << seconds + 1 << "\n";
        ll ans = b;
        for(ll & i: x) {
            ans += min(a - 1, i);
        }  
        cout << ans << "\n";
    }

}
