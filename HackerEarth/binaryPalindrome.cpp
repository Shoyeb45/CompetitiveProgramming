#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

set<int> palindromes = {0, 1};

string toBinary(ll n) {
    if(n == 0)
        return "0";

    string ans = "";
    while(n != 0) {
        int digit = n % 2;
        ans += ('0' + digit);
        n /= 2;
    }
    return ans;
}
ll  toNum(string s) {
    ll ans = 0;
    for(ll i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            ans += (1LL << i);
        }
    }
    return ans;
}

void calcPalindrome() {
    ll range = (1 << 15);
    for(ll n = 0; n <= range; n++) {
        string first = toBinary(n);
        string last = first;
        reverse(last.begin(), last.end());

        // Even
        string current = first + last;
        if(current.back() == '1')
            palindromes.insert(toNum(current));
        
        current = last + first;
        if(current.back() == '1')
            palindromes.insert(toNum(current));
        
        // odd
        current = first + "0" + last;
        if(current.back() == '1')
            palindromes.insert(toNum(current));

        current = first + "1" + last;
        if(current.back() == '1')
            palindromes.insert(toNum(current));
        
        // last + first
        current = last + "0" + first;
        if(current.back() == '1')
            palindromes.insert(toNum(current));

        current = last + "1" + first;
        if(current.back() == '1')
            palindromes.insert(toNum(current));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    calcPalindrome();
    while(t--) {
		ll n;
		cin >> n;
        auto numIdx = palindromes.upper_bound(n);
        ll ans = LONG_LONG_MAX;

        if(numIdx != palindromes.end())
            ans = min(ans, (ll)abs(n - (*numIdx)));

        if(numIdx != palindromes.begin()){
            numIdx--;
            ans = min(ans, (ll)abs(n - (*numIdx)));
        }

        cout << ans << "\n";
    }
    return 0;
}
