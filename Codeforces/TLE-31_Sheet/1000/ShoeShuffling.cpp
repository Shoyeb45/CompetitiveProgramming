#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;
bool isAllEqual(vector<int> &a) {
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] != a[i + 1]) {
            return false;
        }
    }

    return true;
} 

void solve() {
    cin >> n;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }

    
    if(isAllEqual(a) && n != 1) {
        for(int i = 2; i <= n; i++) {
            cout << i << " ";
        }

        cout << 1 << '\n';  
    }
    else{
        // map<int, int> mp;
        // for(auto x: a) {
        //     mp[x]++;
        // }

        // for(auto it: mp) {
        //     if(it.second == 1) {
        //         cout << -1 << "\n";
        //         return;
        //     }
        // }
        
        for(int i = 0; i < n; ) {
            int curr = a[i], cnt = 0;
            while(i < n && a[i] == curr) {
                cnt++, i++;
            }

            if(cnt == 1) {
                cout << -1 << "\n";
                return;
            }
        }

        int i = 0;
        while(i < n) {
            int curr = a[i];
            int currInd = i + 1;
            i++;
            while(i < n && a[i] == curr) {
                cout << i + 1 << " ";
                i++;
            }
            cout << currInd << " ";
        }
        cout << "\n";
    }
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}