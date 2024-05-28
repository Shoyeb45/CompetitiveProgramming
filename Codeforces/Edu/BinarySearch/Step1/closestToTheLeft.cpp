#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int lowerBound(vector<int> &a, int x) {
    int l = 0, r = a.size() - 1;
    int ans = -1;

    while(l <= r) {
        int m = (l + r)/2;
        if(a[m] <= x) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    
    while (q--) {
        int x; cin >> x;
        cout << lowerBound(a, x) << "\n";
    }
    
    return 0;
}
