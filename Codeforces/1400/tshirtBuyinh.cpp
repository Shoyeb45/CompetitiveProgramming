#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    vector<int> a(n);
    vector<int> b(n);
    loop(i, n) {
        cin >> p[i];
        cin >> a[i];
        cin >> b[i];
    }

    int m;
    cin >> m;
    vector<int> c(m);
    loop(i, m)  cin >> c[i];  
    
}