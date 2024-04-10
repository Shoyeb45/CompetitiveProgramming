#include<bits/stdc++.h>
using namespace std;
#define loop(i, n)  for(int i = 0 ; i < n; i++)
int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b;
        cin >> xk >> yk;
        cin >> xq >> yq;
        
        set<pair<int, int>> vp;

        vp.insert({xk + a, yk + b});
        vp.insert({xk - a, yk + b});
        vp.insert({xk + b, yk + a});
        vp.insert({xk - b, yk + a});
        vp.insert({xk + b, yk - a});
        vp.insert({xk - b, yk - a});
        vp.insert({xk + a, yk - b});
        vp.insert({xk - a, yk - b});

        int ans = 0;
        for(auto i : vp) {
            int x = i.first;
            int y = i.second;
            if((x + a == xq && y + b == yq) || (x - a == xq && y - b == yq) || (x + b == xq && y + a == yq) || (x - b == xq && y - a == yq) || (x + b == xq && y - a == yq) || (x - b == xq && y + a == yq) || (x + a == xq && y - b == yq) || (x - a == xq && y + b == yq))    
                ans++;
        }

        cout << ans << "\n";
    }
    
}