#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        vector<ll> b;
        vector<ll> c;
            sort(a.begin(), a.end());

            if(n % 2 == 1) {
                for(int i = 0 , j = n - 1; i < (n / 2); i++, j--) {
                    if(a[i] % a[j] == 0) {   
                        b.push_back(a[j]);
                        b.push_back(a[i]);
                    } else {
                        b.push_back(a[i]);
                        c.push_back(a[j]);
                    }
                }
                bool check = true;
                for(int i = 0 ; i < b.size(); i++) {
                    if(b[i] % a[n/2] != 0)  check = check && true;
                    else {
                        check = false;
                        b.push_back(a[n/2]);
                        break;
                    }
                }
                if(check)   c.push_back(a[n/2]);
            } else {
                for(int i = 0 , j = n - 1; i < n - 1 ; i++, j--) {
                    if(a[i] % a[j] == 0) {   
                        b.push_back(a[j]);
                        b.push_back(a[i]);
                    } else {
                        b.push_back(a[i]);
                        c.push_back(a[j]);
                    }
                }
               
            }

            cout << b.size() << " " ;
            cout << c.size() << "\n";
            for(int i = 0 ; i < b.size(); i++)  cout << b[i] << " ";
            cout << "\n";
            for(int i = 0 ; i < c.size(); i++)  cout << c[i] << " ";
            cout << "\n";
        }
    }
    
}