#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool sorted(vector<int> &a, int start, int end) {
    for(int i = start; i < end; i++) {
        if(a[i] > a[i + 1])
            return false;
    }
    return true;
}


void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    loop(i, n)  
        cin >> a[i];
    
    if(sorted(a, 0, n - 1)) {
        cout << "YES\n";
        return;
    }
    
    int mx_index = 0;
    loop(i, n - 1) {
        if(a[i] > a[i + 1]) {
            mx_index = i;
            break;
        }
    }    

    if(sorted(a, 0, mx_index) && sorted(a, mx_index + 1, n - 1) && a[0] >= a[n - 1])
        cout << "YES\n";
    else
        cout << "NO\n";
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
