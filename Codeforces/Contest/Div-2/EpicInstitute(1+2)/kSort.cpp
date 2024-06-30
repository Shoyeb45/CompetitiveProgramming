#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n);
    loop(i, n)
        cin >> a[i];
    
    if(is_sorted(range(a)) || n == 1) {
        cout << 0 << '\n';
    } else {
        vector<int> diff;
        int i = 0;
        while(i < n - 1) {
            int j = i + 1;
            while(j < n && a[i] > a[j]) {
                diff.push_back(a[i] - a[j]);
                j++;
            }
            i = j;
        }
        sort(range(diff));
        
        ll ans = 0;
        // loop(i, diff.size())
        //     cout << diff[i] << ' ';
        // cout << endl;
        ll difference = 0;
        loop(i, diff.size()) {
            ans += (diff.size() - i + 1) * (diff[i] - difference);
            difference = diff[i];
            // cout << "ans : " << ans << '\n';
            // for(int j = i + 1; j < diff.size(); j++) {
            //     diff[j] -= diff[i];
            // }
        }
        cout << ans << '\n';
    }
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
