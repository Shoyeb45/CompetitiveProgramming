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
vector<int> h;
void solve() {
    cin >> n;
    h.resize(n);
    loop(i, n)
        cin >> h[i];
    
    int ans = 0;
    while(h[0]) {
        for(int i = 0; i < n - 1; i++) {
            if(h[i] > h[i + 1]) {
                h[i]--;
            }
        }
        if(h[n - 1])
            h[n - 1]--;
        ans++;
    }
    cout << ans << '\n';
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
