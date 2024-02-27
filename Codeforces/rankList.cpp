#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        vp.push_back(make_pair(x, y));
    }

    sort(vp.begin(), vp.end());
    
    for(int i=0; i<n-1; i++) {
        int begin = i;
    }
    int ind = n-k;
    int cnt = 0;
    for(int i=0; i<n; i++) {
            if(vp[i].first == vp[ind].first && vp[i].second == vp[ind].second) {
                cnt++;
        }
    }
    
    cout << cnt;
    
    
    return 0;
}