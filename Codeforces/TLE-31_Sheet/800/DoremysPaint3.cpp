#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n ; i++) cin >> a[i];

        sort(a.begin(), a.end());

        if(n % 2 == 1) {
            int cnt1 = 1, cnt2 = 1;
            bool count1 = true;
            for(int i = 0; i < n - 1 ; i++) {
                if(count1) {
                    if(a[i] == a[i+1])  cnt1++;   
                    else    count1 = false;
                } else {
                    if(a[i] == a[i+1])  cnt2++;   
                }
            }

            if((cnt1 == n/2 && cnt2 == n - n/2) || (cnt2 == n/2 && cnt1 == n - n/2))    cout << "YES\n";
            else    cout << "NO\n";
        } else {
            
        }
    }
    
}