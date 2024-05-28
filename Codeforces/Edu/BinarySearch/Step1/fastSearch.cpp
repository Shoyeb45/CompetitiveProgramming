#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int lb(vector<int> &a, int x) {
    int l = 0, r = a.size() - 1;
    int ans = a.size();
    while(l <= r) {
        int m = (l + r)/2;
        if(a[m] >= x) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int up(vector<int> &a, int x) {
    int l = 0, r = a.size() - 1;
    int ans = 0;
    while(l <= r) {
        int m = (l + r)/2;
        if(a[m] <= x) {
            ans = m + 1;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    int k;
    cin >> k;
    sort(a.begin(), a.end());

    while (k--) {
        int l, r;
        cin >> l >> r;
        // cout << "UB: " << up(a, r)<< '\n';  
        // cout << "LB: " << lb(a, l) < < "\n";  
        cout << up(a, r) - lb(a, l) << " ";  
    }
    
    return 0;
}
