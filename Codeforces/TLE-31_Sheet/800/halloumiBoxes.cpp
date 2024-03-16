#include<bits/stdc++.h>
using namespace std;

bool isAsce(vector<int> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] >= a[i+1])   ans = ans && true;
        else    ans = false;
    }
    return ans;
}

bool isDesc(vector<int> &a) {
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

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0 ; i < n; i++) cin >> a[i];

        if(isDesc(a))   cout << "YES\n";
        else if(isAsce(a) && k != 1)    cout << "YES\n";
        else if ( k == 1 )   cout << "NO\n";
        else    cout << "YES\n";
        
    }
    
}