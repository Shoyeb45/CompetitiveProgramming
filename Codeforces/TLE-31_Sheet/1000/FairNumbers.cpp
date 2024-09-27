#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n;

bool isFairNumber(ll n) {
    ll temp = n;
    while(n > 0) {
        int digit = n % 10;

        if(digit != 0 && temp % digit != 0) {
            return false;
        }
        n /= 10;
    }

    return true;
}
void solve() {
    cin >> n;
    ll sum = 0;
    
    for( ; ; n++) {
        if(isFairNumber(n)) {
            break;
        }
    }
    cout << n << endl;
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}