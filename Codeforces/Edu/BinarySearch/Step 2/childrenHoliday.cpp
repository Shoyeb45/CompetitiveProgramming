#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;


bool check(vector<vector<int>> &a, int mid, int m, vector<int> &balloon) {
    vector<int> ans(a.size());
    int n = 0;
    loop(i, a.size()) {
        int cycle = ((a[i][0] * a[i][1]) + a[i][2]);
        int ballons = ((mid/cycle) * a[i][1]) + min(a[i][1], ((mid % cycle)/a[i][0]));
        // cout << "Balloons: " << ballons << '\n';
        n += (ballons);
        ans[i] = ballons;
        mid -= mid/cycle;
    }
    cout << "n: " << n << '\n';
    if(n >= m) {
        balloon = ans;
    }

    return n >= m;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n, vector<int> (3, 0));
    loop(i, n) {
        loop(j, 3) {
            cin >> a[i][j];
        }
    }
    
    int low = 0, high = 1;
    vector<int> balloon(n);
    // while(!check(a, high, m, balloon)) {
    //     high *= 2;
    // }
    int ans = high;
    // while(low <= high) {
    //     int mid = low + (high - low)/2;
    //     if(check(a, mid, m, balloon)) {
    //         ans = mid;
    //         high = mid - 1;
    //     } else {
    //         low = mid + 1;
    //     }
    // } 
    
    check(a, 12, m, balloon);
    cout << ans << '\n';
    loop(i, n)
        cout << balloon[i] << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
