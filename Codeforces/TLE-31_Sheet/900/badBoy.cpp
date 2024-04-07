#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;



int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<pair<ll, pair<ll, ll>> > vp;
        vp.push_back(make_pair( abs(1 - x) + abs(1 - y), make_pair(1, 1)));
        vp.push_back(make_pair( abs(1 - x) + abs(m - y), make_pair(1, m)));
        vp.push_back(make_pair( abs(n - x) + abs(1 - y), make_pair(n, 1)));
        vp.push_back(make_pair( abs(n - x) + abs(m - y), make_pair(n, m)));
        sort(vp.begin(), vp.end());
        

        if(x == 1 && y == 1) cout << vp[3].second.first << " " <<  vp[3].second.second << " " << vp[3].second.first << " " <<  vp[3].second.second << endl;
        else {
            x = vp[3].second.first, y = vp[3].second.second;
        vector<pair<ll, pair<ll, ll>> > vp1;
        vp1.push_back(make_pair( abs(1 - x) + abs(1 - y), make_pair(1, 1)));
        vp1.push_back(make_pair( abs(1 - x) + abs(m - y), make_pair(1, m)));
        vp1.push_back(make_pair( abs(n - x) + abs(1 - y), make_pair(n, 1)));
        vp1.push_back(make_pair( abs(n - x) + abs(m - y), make_pair(n, m)));
        sort(vp1.begin(), vp1.end());

        cout << x << " " << y << " " << vp1[3].second.first << " " << vp1[3].second.second << "\n" ;
        }
    }
}
