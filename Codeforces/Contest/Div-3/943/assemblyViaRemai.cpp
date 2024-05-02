#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> x(n - 1);
    loop(i, n - 1)  cin >> x[i];
    
    if(n == 2) {
        cout << x[0] + 1 << " " << x[0] << endl;
        return;
    }

    cout << x[0] + 1 << " ";
    int d = x[0] + 1;

    for(int i = 0; i < n - 2; i++) {
        if(x[i] > x[i + 1]) {
            cout << x[i] << " ";
            d = x[i];
        } else {
            for(int j = x[i + 1] + 1; ; j++) {
                if(j % d == x[i]) {
                    cout << j << " ";
                    d = j;
                    break;
                }
            }
        }
    }

    cout << x[n - 2] << endl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
