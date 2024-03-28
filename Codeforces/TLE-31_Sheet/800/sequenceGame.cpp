#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSorted(vector<ll> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] <= a[i+1])   ans = ans && true;
        else    ans = false;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        
        for(int i = 0; i < n ; i++) cin >> b[i];

        if(isSorted(b)) {
            cout << b.size() << endl;
            for(int i = 0; i < n ; i++) cout << b[i] << " ";
            cout << "\n";
        } else {
            vector<ll> a;
            a.push_back(b[0]);
            for(int i = 1; i < n; i++) {
                if(b[i] >= b[i-1])  a.push_back(b[i]);
                else {
                    if(b[i-1] - b[i] <= b[i])   a.push_back(b[i-1] - b[i]);
                    else    a.push_back(b[i]);
                    a.push_back(b[i]);
                }
            }

            cout << a.size() << "\n";
            for(int i = 0 ; i < a.size(); i++)  cout << a[i] << " ";
            cout << "\n";
        }
    }
}