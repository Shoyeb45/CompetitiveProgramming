#include<bits/stdc++.h>
using namespace std;

int absolute(int x, int y) {
    if (x - y >= 0) return x - y; 

    return -1 * (x - y);
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        set<int> s;
        for(int i = 0; i < n ; i++){
            int temp;
            cin >> temp;
            a.push_back(temp);
            s.insert(temp);
            }


        if(s.size() == 1)   cout << "YES\n";
        else if (s.size() > 2)  cout << "NO\n";
        else {
            sort(a.begin(), a.end());

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
            if(absolute(cnt1, cnt2) <= 1)   cout << "YES\n";
            else    cout << "NO\n";

            }


        // if(n % 2 == 1) {
        //     if((cnt1 == n/2 && cnt2 == n - n/2) || (cnt2 == n/2 && cnt1 == n - n/2) || (cnt1 == n))    cout << "YES\n";
        //     else    cout << "NO\n";
        // } else {
        //     if(cnt1 == cnt2 || cnt1 == n)    cout << "YES\n";
        //     else    cout << "NO\n";
        // }


    }
    
}