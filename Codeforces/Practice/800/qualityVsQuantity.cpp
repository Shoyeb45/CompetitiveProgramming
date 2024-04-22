#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007; 

void solve() {  
    int n;
    cin >> n;
    ll sumB = 0;
    vector<int> a(n);
    loop(i, n) { 
        cin >> a[i];
        sumB += a[i];
    }

    sort(a.begin(), a.end());

    ll sumR = 0;
    for(int i = n - 1; i >= 0; i--) {
        sumR += a[i], sumB -= a[i];
        if(i > n/2 && sumR > sumB) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    
    return 0;
    
}
