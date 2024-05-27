#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int x; cin >> x;
    vector<int> ans;    

    while(x > 0) {
        if(x % 2 == 0) {
            ans.push_back(0);
        } else {
            if(((x - 1) / 2) % 2 == 0){
                ans.push_back(1);
                x -= 1;
            } else {
                ans.push_back(-1);
                x += 1;
            }   
        }  
        x = x / 2;
    }

    cout << ans.size() << '\n';
    loop(i, ans.size()) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
