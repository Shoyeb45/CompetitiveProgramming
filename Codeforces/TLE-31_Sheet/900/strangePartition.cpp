#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        ll min = 0;

        vector<int> a(n);
        loop(i, n) {
            cin >> a[i];
            min += a[i];
        }

        ll max = 0;
        loop(i, n) 
            max += (a[i] + x - 1)/x;
        cout << (min + x - 1)/x << " " << max << "\n";

    }
    
    return 0;
}
