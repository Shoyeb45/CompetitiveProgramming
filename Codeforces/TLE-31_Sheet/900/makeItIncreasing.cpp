#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;

bool isAsce(vector<int> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] > a[i+1])   ans = ans && true;
        else    ans = false;
    }
    return ans;
}

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

        if(isDesc(a))   cout << 0 << "\n";
        else if(isAsce(a))  cout << -1 << "\n";
        else {
            
        }
    }
}