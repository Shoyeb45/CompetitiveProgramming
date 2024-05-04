#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    int mx = 0;
    ll sum = 0;
    loop(i, n) {
        int a, b;
        cin >> a >> b;
        sum += a;
        mx = max(b - a, mx);
    }
    sum += mx;
    
    cout << sum ;
    return 0;
}
