#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, k, p_b, p_s;
    cin >> n >> k >> p_b >> p_s;
    p_b--;
    p_s--;
    vector<int> p(n);
    vector<int> a(n);
    loop(i, n)  {
        cin >> p[i];
        p[i]--;
    }
    loop(i, n)  cin >> a[i];

    vector<int> bodya;
    vector<int> sasha;

    // for(auto i: p) {
    //     cout << i << ' ';
    // }
    cout << "\n";
    int i = p_b;
    bodya.push_back(a[p_b]);
    int temp = k - 1;
    while(temp--) {
        i = p[i];
        if(i == p_b)
            break;
        
        bodya.push_back(a[i]);
    }
    temp = k - 1;
    i = p_s;
    sasha.push_back(a[p_s]);
    while(temp--) {
        i = p[i];
        if(i == p_s)
            break;
        
        sasha.push_back(a[i]);
    }
    
    for(auto i : bodya) {
        cout << i << ' ';
    }
    cout << endl;
    for(auto i: sasha) {
        cout << i << " ";
    }
    cout << endl;
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
