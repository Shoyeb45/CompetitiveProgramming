#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i, n) for(int i = 0; i < n; i++)

bool isAllEqual(vector<ll> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] == a[i+1])  ans = ans && true;
        else {  
            ans = false;
            return ans;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0 ; i < n; i++) cin >> a[i];
        
        if(isAllEqual(a))   cout << -1 << "\n";
        else {
            sort(a.begin(), a.end());
            
            ll ind = 0;
            while(a[ind] == a[0])   ind++;

            cout << ind << " " << n - ind << "\n";

            loop(i, ind) cout << a[i] << " ";
            cout << "\n";
            for(int i = ind; i < n; i++)    cout << a[i] << " ";
            cout << endl;
    }
    
}
}