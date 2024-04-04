#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;

    set<int> s; 
    int max = 0, cnt = 0;
    loop(i, 2 * n) {
        int x;
        cin >> x;
        
        if(s.find(x) == s.end())    s.insert(x);
        else    s.erase(s.find(x));
        
        if(max <= cnt) max = cnt;
    }
    cout << cnt;
}