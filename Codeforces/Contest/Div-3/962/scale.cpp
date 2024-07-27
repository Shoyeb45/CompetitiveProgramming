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

int n, k;
void solve() {
    cin >> n >> k;
    vector<string> a(n);
    loop(i, n) {
        cin >> a[i];
    }
    vector<string> b;

    int i = 0;
    for(int i = 1; i <= n / k; i++) {
        int x = k * i - 1;
        string temp = "";
        for(int j = 1; j <= n / k; j++) {
            int y = k * j - 1;
            temp += a[x][y];
        }
        b.push_back(temp);
    }

    loop(i, b.size()) {
        cout << b[i] << '\n';
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
