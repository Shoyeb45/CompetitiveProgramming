#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;


void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    loop(i, n)  cin >> p[i];

    if(n == 2) {
        cout << 2 << endl;
        return;
    }
    bool check = false;
    loop(i, n - 1) {
        if(p[p[i] - 1] == i + 1) {
            check = true;
            break;
        }
    }
    if(check) {
        cout << 2 << endl;
        return;
    }

    cout << 3 << endl;
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
