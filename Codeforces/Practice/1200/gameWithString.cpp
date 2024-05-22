#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    stack<char> temp_char;
    int number_of_moves = 0;
    temp_char.push(s[0]);
    
    for(int i = 1; i < s.size(); i++) {
        if(temp_char.top() == s[i]) {
            number_of_moves++;
            temp_char.pop(); 
        } else {
            temp_char.push(s[i]);
        }
    }
    
    
    string ans = number_of_moves % 2 == 0? "NO\n": "YES\n";
    cout << ans;
    return 0;
}
