#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(vector<ll> &a, ll k, double mid) {
    ll cnt = 0;
    loop(i, a.size()) {
        cnt += (a[i]/mid);
    }
    return cnt >= k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    loop(i, n) {
        cin >> a[i];
    }
    double low = 1, high = 1e7, ans = 0;

    int iter = 45;
    while(iter--) {
        double mid = low + (high - low)/2;
        if(check(a, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}
