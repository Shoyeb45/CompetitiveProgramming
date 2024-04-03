#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
void minOpe(vector<int> &a) {
    int cnt = 0;

    for(int i = 0; i < a.size() - 1; ) {
        int j = 0;
        for(j = i + 1 ; j < a.size(); j++) {
            if((a[i] % 2 == 0 && a[j] % 2 == 0) || (a[i] % 2 == 1 && a[j] % 2 == 1)) {
                cnt++;
                i = j;
                continue;
            } else if((a[i] % 2 == 1 && a[j] % 2 == 0) || (a[i] % 2 == 0 && a[j] % 2 == 1)) {
                i = j;
                break;
            }
        }

    }

    cout << cnt << endl;
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

        if(n == 1)  cout << 0 << endl;
        else {
            minOpe(a);
        }
    }
    
}