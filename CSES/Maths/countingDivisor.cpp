#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
#define MX 1e6

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;
vector<int> prime(MX + 1, 0);

void calcPrime() {
    for(int i = 2; i <= MX; i++) {
        if(prime[i] == 0) {
            for(int j = i; j <= MX; j += i) {
                prime[j] = i;
            } 
        }
    }
}
// void solve() {
//     cin >> n;
//     int ans = 0;
//     for(int i = 1; i * i <= n; i++) {
//         if(n % i == 0)
//             ans += (i * i == n? 1: 2);
//     }
//     cout << ans << '\n';
// }

void solve2() {
    cin >> n;
    ll ans = 1;
    while(n != 1) {
        int cnt = 0;
        int p = prime[n];
        while(n % p == 0) {
            cnt++;
            n /= p;
        }
        ans *= (cnt + 1);
    }
    cout << ans << '\n';
}

int main() {
    calcPrime();
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve2();
    }
    
    return 0;
}
