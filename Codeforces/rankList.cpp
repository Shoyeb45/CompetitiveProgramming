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
    reverse(vp.begin(), vp.end());
    for(int i=0; i<n-1; i++) {
        if(vp[i].first == vp[i+1].first && vp[i].second > vp[i+1].second) {
            int temp = vp[i].second;
            vp[i].second = vp[i+1].second;
            vp[i+1].second = temp;
        }
    }
    

    return 0;
}