#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair <ll, ll> > v(n);
        for(int i = 0 ; i < n ; i++ ) {
            cin >> v[i].first;
            v[i].second = i + 1;
        }

        sort(v.begin(), v.end());
        int cnt = 0;

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = i + 1 ; j < n ; j++) {
                if(v[i].first * v[j].first > 2 * n) break;
                cnt += (v[i].first * v[j].first == v[i].second + v[j].second);
            }
        }

        cout << cnt <<"\n";
    }  
}