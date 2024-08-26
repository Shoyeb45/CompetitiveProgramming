#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    string s;
    cin >> s;

    int sum1 = 0, sum2 = 0;

    for(int i = 0; i <= 2; i++) {
        sum1 += (int)(s[i] - '0');
    }    

    for(int i = 5; i >= 3; i--) {
        sum2 += (int)(s[i] - '0');
    }

    // cout << sum1 << " " << sum2 <<'\n';
    if(sum1 == sum2) {
        cout << "YES\n"; 
    }
    else {
        cout << "NO\n";
    }
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
