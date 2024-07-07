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

int n, m;
vector<string> a;
vector<string> b;
void solve() {
    cin >> n >> m;
    a.resize(n);
    b.resize(n);

    loop(i, n) {
        cin >> a[i];
    }
    loop(i, n) {
        cin >> b[i];
    }

    ll sum = 0, pos = 0;
    loop(i, n) {
        loop(j, m) {
            sum += abs((b[i][j] - '0') - (a[i][j] - '0'));
            pos += (b[i][j] != a[i][j]);
        }
    }
    // cout << "req: " << pos << ' ' << "Sum: ";
    // cout << sum << '\n';
    loop(i, n)
        cout << a[i] << " " << b[i] << '\n';
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
