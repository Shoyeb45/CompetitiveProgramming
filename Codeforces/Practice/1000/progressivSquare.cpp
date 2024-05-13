#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, c, d;    
    cin >> n >> c >> d;

    vector<int> b(n*n);
    loop(i, n*n)    cin >> b[i];

    sort(b.begin(), b.end());
    int a = b[0];
    vector<ll> matrix;

    // loop(i, n) {
    //     matrix.push_back(a);
    //     a += d;
    // }

    // loop(i, n) {
    //     int new_a = matrix[i];
    //     loop(i, n - 1) {
    //         new_a += c;
    //         matrix.push_back(new_a);
    //     }
    // }
    loop(i, n*n) {
        matrix[i][j] = a + i * d + j * c;
    }
    sort(matrix.begin(), matrix.end());

    loop(i, n*n) {
        if(b[i] != matrix[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
