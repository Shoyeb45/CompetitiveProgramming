#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

bool all_equal(vector<int> &a) {
    loop(i, a.size() - 1) {
        if(a[i] != a[i + 1])
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    
    if(all_equal(a)) {
        cout << "NO\n";
        return;
    }
    string s(n, '#');
    int i = 0; 
    for(i = 0; i < n/2; i++) {
        if(a[n - i - 1] - a[i] != 0) {
            s[n - i - 1] = 'B';
            s[i] = 'B';
        } else {
            s[n - i - 1] = 'R';
            s[i] = 'R';

        }
    }
    s[n/2] = 'R';
    cout << "YES\n";
    cout << s << '\n';
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
