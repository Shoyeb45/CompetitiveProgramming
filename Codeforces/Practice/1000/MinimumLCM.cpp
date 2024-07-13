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

int x;
void solve() {
    cin >> x;
    pair<int, int> p;

    if(x % 2 == 0) {
        p.first = p.second = x / 2;
    } else {
        int a = 1;
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) {
                a = x / i;
                break;
            }
        }
        p.first = a, p.second = x - a;
    }
    cout << p.first << " " << p.second << '\n';
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
