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

class Solution {
public:
    int n;
    string s;

    Solution() {
        
    }
    void solve() {
        int i = 0;
        for(i = 0; i < n - 1; i++) {
            if(s[i] > s[i + 1]) {
                cout << "YES\n";
                cout << i + 1 << " " << i + 2 << '\n';
                return;
            }
        }
        cout << "NO\n";
    }
};

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    Solution sol;
    while (tt--) {
        cin >> sol.n >> sol.s;
        sol.solve();
    }
    
    return 0;
}
