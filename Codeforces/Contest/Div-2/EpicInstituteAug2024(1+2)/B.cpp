#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);

    loop(i, n) {
        cin >> a[i];
    }
    loop(i, n) {
        cin >> b[i];
    }

    if((n & 1) == 1) {
        if(n == 1) {
            if(a[0] == b[0]) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
            return;
        }
        if(a[n / 2] == b[n / 2] && a[(n / 2) - 1] == b[(n / 2) - 1] && a[(n / 2) + 1] == b[(n / 2) + 1] || ) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        if(a[n / 2] == b[n / 2] && a[(n / 2) - 1] == b[(n / 2) - 1]) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
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
