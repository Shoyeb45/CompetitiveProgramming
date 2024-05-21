#include<bits/stdc++.h>
using namespace std;

void prefixSum(vector<int> &p,vector<int> &v) {
    v.push_back(p[0]);

    for(int i=1; i < p.size(); i++) {
        v.push_back(v[i-1] + p[i]);
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> time;

    for(int i=0; i<n; i++)  {
        int temp;
        cin >> temp;
        time.push_back(temp);
    }
    sort(time.begin(), time.end());
    vector<int> pS;
    prefixSum(time, pS);
    
    if(pS.size() == 1 && pS[0] >= t) cout << 1;
    else if (pS.size() == 1 && pS[0] < t)   cout << 0;
    else {
    for(int i=0; i<=n-2; i++) {
        if(pS[i+1] > t && pS[i] <= t) {
            cout << i+1;
        }
    }
    }

    return 0;
}
