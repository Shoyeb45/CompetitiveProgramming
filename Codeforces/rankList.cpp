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

    cout <<"\n";

    for(int i=0; i<n; i++) cout << vp[i].first << " " << vp[i].second << '\n';
    
    for(int i=0; i<n-1; i++) {
        if(vp[i].first == vp[i+1].first && vp[i].second > vp[i+1].second) {
            int temp = vp[i].second;
            vp[i].second = vp[i+1].second;
            vp[i+1].second = temp;
        }
    }
    int ind = k- 1;
    int cnt = 1;
    for(int i=0; i<n; i++) {
        if(i != ind) {
            if(vp[i].first == vp[ind].first && vp[i].second == vp[ind].second) {
                cnt++;
            }
        }
    }
    cout <<"\n";

    for(int i=0; i<n; i++) cout << vp[i].first << " " << vp[i].second << '\n';

    cout << cnt;
    return 0;
}