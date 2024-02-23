#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<pair<int, int> >  p;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    sort(p.begin(), p.end());
    bool ans = false;
    for(int i=0; i<n; i++) {
        if(p[i].first < s) {
            s += p[i].second;
            ans = true;
        } else {
            ans = false;
        }
    }

     ans ? cout << "YES" : cout <<"NO";
}