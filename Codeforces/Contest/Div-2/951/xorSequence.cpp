#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;
    ll k = 0;
    vector<int> bits_x;
    vector<int> bits_y;
    while(x && y) {
        // bits_x.push_back(x % 2);
        // bits_y.push_back(y % 2);
        if(x % 2 == y % 2)
            k++;
        else    
            break;
        x /= 2;
        y /= 2;
    }
    if(!x) {
        while(y) {
            if(y % 2 == 0) {
                k++;
            } else {
                break;
            }
            y /= 2;
        }
    }
    if(!y) {
        while(x) {
            if(x % 2 == 0) {
                k++;
            } else {
                break;
            }
            x /= 2;
        }
    }
    // reverse(bits_x.begin(), bits_x.end());
    // reverse(bits_y.begin(), bits_y.end());
    // cout << "BITS_X \n" ;
    // loop(i, bits_x.size())
    //     cout << bits_x[i] << ' ';
    // cout<<'\n';
    // cout << "BITS_Y \n" ;
    // loop(i, bits_y.size())
    //     cout << bits_y[i] << ' ';
    // cout<<'\n';
    // int i = 0;
    // while(i < min(bits_x.size(), bits_y.size())) {
    //     if(bits_x[i] == bits_y[i])
    //         k++;
    //     else
    //         break;
    //     i++;
    // }
    ll ans = pow(2, k);
    // cout << "k: " << k <<'\n';
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
