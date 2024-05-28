#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool is_present_bs(vector<int> &a, int target) {
    int l = 0, r = a.size() - 1;
    while(l <= r) {
        int m = (l + r)/2;
        if(a[m] == target) {
            return true;
        } else if(a[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    while (k--) {
        int x;
        cin >> x;
        cout << (is_present_bs(a, x)? "YES\n": "NO\n") ;
    }
    
    return 0;
}
