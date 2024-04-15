#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;

bool isDesc(vector<int> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] < a[i+1])   ans = ans && true;
        else    ans = false;
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

        vector<int> a(n);
        loop(i, n)  cin >> a[i];

        int ans = 0, check = 1;

        for(int i = n - 2; i >= 0; i--) {
            if(a[i + 1] != 0 && a[i + 1] <= a[i]) {
                int cnt = log2(a[i]/a[i + 1]) + 1;
                int div = pow(2, cnt);
                a[i] /= div;
                ans += cnt;
            } 
            if(a[i + 1] == 0)   {
                check = 0;
                break;
            }
        }

        if(check)   cout << ans << "\n";
        else    cout << -1 << "\n";
    }

}