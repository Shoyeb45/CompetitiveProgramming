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
            
        }
    }
}