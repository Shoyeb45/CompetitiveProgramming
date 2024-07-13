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

bool is_triangle(int a, int b, int c) {
    return a + b > c;
}
void solve() {
    cin >> n;
    a.resize(n);
    loop(i, n)
        cin >> a[i];
    sort(range(a));

    for(int i = n - 1; i >= 2; i--) {
        if(is_triangle(a[i - 2], a[i - 1], a[i])) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
