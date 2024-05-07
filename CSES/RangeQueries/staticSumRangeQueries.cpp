#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<ll> prefixSum(vector<ll> &a) {
    vector<ll> ans(a.size());
    ans[0] = a[0];
    for(ll i = 1; i < a.size(); i++) {
        ans[i] = ans[i - 1] + a[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);

    loop(i, n)  cin >> a[i];
    vector<ll> pS = prefixSum(a);

    while (q--) {
        ll i, j;
        cin >> i >> j;
        i--;
        j--;
        if(i == 0) {
            cout << pS[j] << endl;
        } else {
            cout << pS[j] -pS[i - 1] << endl;
        }
    }
    
    return 0;
}
