#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    int temp = n - 1;
    int k = 0;
    while(temp != 1) {
        temp = temp /2 ;
        k++;
    }
    int max = 1 << (k);
    int current = max;
    
    for(int i = 1; i <= max; i++) {
        cout << (max - i) << " ";
    }

    for(int i = 0; i < n - max; i++) {
        cout << (max + i) << " ";
    }
    cout << '\n';
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
