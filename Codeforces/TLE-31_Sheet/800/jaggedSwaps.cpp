#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

bool isSorted(vector<int> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size()-1; i++ ) {
        if(a[i] < a[i+1])   ans = ans && true;
        else ans = ans && false;
    }

   return ans;
}

void sorting(vector<int> &a) {
    for(int i = 1; i < a.size() - 1 ; i++) {
            if(a[i] > a[i+1] && a[i-1] < a[i])  {
                swap(a, i, i+1);
            }
        }
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        if(a[0] == 1)   cout << "YES\n";
        else cout << "NO\n";
    }
    
}