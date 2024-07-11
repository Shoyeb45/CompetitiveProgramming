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

int n, m, k;
string s;
void solve() {
    cin >> n >> m >> k;
    cin >> s;
    if(m >= n) {
        cout << "YES\n";
        return;
    }
    m--;
    int i = 0;
    while(i < n) {
        
    }
    cout << "YES\n";
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
