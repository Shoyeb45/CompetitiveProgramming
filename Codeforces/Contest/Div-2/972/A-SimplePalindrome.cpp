#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    int i = 1;
    char vow[] = {'a', 'e', 'i', 'o', 'u'};
    int track = 1;
    string ans = "";
    if(n <= 5) {
        for(int i = 1; i <= n; i++) {
            ans += (char)vow[track - 1];
            track++;
            if(track % 6 == 0) {
                track = 1;
            }
        }
    }
    else {
        unordered_map<char, int> mp;
        while(n > 0) {
            for(int i = 0; i < 5 && n > 0; i++) {
                mp[vow[i]]++;
                n--;
            }
        }

    
        for(auto it: mp) {
            for(int i = 0; i < it.second; i++) {
                ans += (char)it.first;
            }
        }
    }
    cout << ans << '\n';
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
