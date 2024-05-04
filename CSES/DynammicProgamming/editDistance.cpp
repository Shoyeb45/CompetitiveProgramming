#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

map<char,int> freqChar(string s) {
    map<char, int> m;
    for(auto &ch: s)
        m[ch]++;
    return m;
}

int numberOfEdit(string a, string b) {
    map<char, int> m = freqChar(a.size() >= b.size()? b: a);
    map<char, int> m1 = freqChar(a.size() >= b.size() ? a: b);
    int ans = 0;
    string s = a.size() >= b.size()? a: b;
    for(int i = 0; i < s.size(); i++) {
        if(m.find(s[i]) == m.end()){
            ans++;
            cout << "Hel: " << ans << endl;
        }
        else {
            ans += abs(m1[s[i]] - m[s[i]]);
            cout << "Hii:" << ans << endl ;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a;
    cin >> b;
    
    int x = numberOfEdit(a, b);
    cout << x << endl;
    return 0;
}
