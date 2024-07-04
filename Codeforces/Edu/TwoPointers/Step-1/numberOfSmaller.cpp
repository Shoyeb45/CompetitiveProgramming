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

int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);    

    loop(i, n)
        cin >> a[i];
    loop(i, m)
        cin >> b[i];

    int i = 0;
    for(int x: b) {
        if(x <= a[0]) {
            cout << 0 << " ";
            continue;
        }
        while(i < n && a[i] < x) {
            i++;
        }
        cout << i << ' ' ;
    }
    
   
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
