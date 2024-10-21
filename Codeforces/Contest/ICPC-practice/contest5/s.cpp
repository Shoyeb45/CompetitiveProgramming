#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    multiset<int> mt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(auto x : mp) mt.insert(x.second);

    int ans = 0;

    while(!mt.empty()){
        auto it = mt.end();
        it--;
        int sum = *it;
        mt.erase(it);

        if(sum == k){
            ans++;
            continue;
        }

        while(!mt.empty() && sum <= k){
            auto it = mt.upper_bound(k - sum);
            if(it != mt.begin()){
                it--;
                sum += *it;
                mt.erase(it);
            } 
            else break;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}