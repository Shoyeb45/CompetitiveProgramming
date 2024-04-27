#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> b(n);
    loop(i, n)  cin >> b[i];

    vector<int> a;

    a.push_back(b[0]);
    for(int i = 1; i < n ; i++) {
        int y = b[i];
        while (a[a.size() - 1] == y)
        {
            int x = a[a.size() - 1];
            a.pop_back();
            a.push_back(x + 1);
            y = a[a.size() - 1];
        }
        
        if(a[a.size() - 1] != b[i]) {
            a.push_back(b[i]);
        }
    }

    cout << a.size() << endl;
    return 0;
}
