#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int a, b;
void solve() {
    cin >> a >> b;

    if(a == 0) {
        if(b % 2 == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
        return;
    }

    if(b == 0) {
        if(a % 2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return;
    }


    if(a % 2 == 0 && b % 2 == 0 || (a % 2 == 0 && b % 2 == 1)) {
        cout << "YES\n";
    }
    else if(a % 2 == 1 && b % 2 == 1 || (a % 2 == 1 && b % 2 == 0)) {
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
