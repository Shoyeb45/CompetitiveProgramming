#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
int n, tt;
vector<ll> a;

int lb(int target) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int ub(int target) {
    int low = 0, high = n - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] <= target) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans + 1;
}
void solve() {
    int l, r;
    cin >> l >> r;
    
    cout << ub(r) - lb(l) << '\n';
}
int main() {
    freopen("haybales.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("haybales.out", "w", stdout);
    tt = 1;
    cin >> n >> tt;
    a.resize(n);

    loop(i, n)
        cin >> a[i];
    sort(range(a));

    while (tt--) {
        solve();
    }
    
    return 0;
}
