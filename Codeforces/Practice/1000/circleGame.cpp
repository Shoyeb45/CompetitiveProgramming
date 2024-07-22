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

int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    if((n & 1) == 1) {
        cout << "Mike\n";
    } else {
        int mn = *min_element(range(a));
        int ind = 0;
        loop(i, n) {
            if(mn == a[i]) {
                ind = i;
                break;
            }
        }
        if(ind % 2 == 0)
            cout << "Joe\n";
        else 
            cout << "Mike\n";
    }
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
