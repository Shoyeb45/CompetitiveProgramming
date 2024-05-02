#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool isSubs(string o, string ss) {
    int i=0, j=0;

    while(i < o.size() && j < ss.size()) {
        if(o[i] == ss[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if(j == ss.size()) {
        return true;
    } 

    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;

    // if(a[0] != b[0]) {
    //     cout << 0 << endl;
    //     return;
    // }

    int k = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            k++;
            j++;
            i++;
        } else {
            while(j < m) {
                if(a[i] == b[j]) {
                    k++;
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
    }
    // int k = 0;
    // string s = "";
    // for(int i = 0; i < n; i++) {
    //     s = s + a[i];
    //     // cout << s << endl;
    //     if(isSubs(b, s)) {
    //         k = s.size();
    //     } else {
    //         break;
    //     }
    // }
    cout << k << endl;
    return;
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
