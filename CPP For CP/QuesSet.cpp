#include<bits/stdc++.h>
// sets practice question - Andryusha and socks
using namespace std;


int main() {
    int n;
    cin >> n ;
    int ans = -1;
    set<int> s;

    for(int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;

        s.insert(x);
        if(s.find(x) == s.end()) {
        } else {
            if(s.size() > 1)    s.erase(s.find(x));
        }

        if(s.size() > ans) {
            ans = s.size();
        }
    }

    cout << ans;
}