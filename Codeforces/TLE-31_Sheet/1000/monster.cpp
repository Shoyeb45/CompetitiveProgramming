#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, k;   cin >> n >> k;
    vector<pair<int, int>> vp(n);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vp[i].first = x;
        vp[i].second = i;
    }

    loop(i, n) 
        vp[i].first = (vp[i].first % k == 0)? k: vp[i].first % k;
    
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());

    loop(i, n) {
        swap(vp[i].first, vp[i].second);
    }   

    int i = 0;
    while(i < n - 1) {
        int start = 0, j = n - 1;
        if(vp[i].second == vp[i + 1].second) {
            start = i;
            j = i;
            while(vp[i].second == vp[j].second && j < n) {
                j++;
            }
        sort(vp.begin() + start, vp.begin() + j);
        i = j;
        } else {
            i++;
        }
        
    }

    loop(i, n) {
        cout << vp[i].first + 1 << " ";
    }
    cout << endl;
}

void swap(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
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
