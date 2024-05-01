#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    loop(i, n)  cin >> a[i];

    ll sum = 0;
    loop(i, n) {
        for(int j = i + 1; j < n; j++) {
            sum += max((int)(a[j] - a[i]), 0);
        }
    }
    cout << sum << endl;
    return 0;
}
