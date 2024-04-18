#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    string s;
    cin >> s;

    string reveStr;
    for(int i = s.length() - 1; i >= 0; i--)    reveStr += s[i];
    
    cout << reveStr;
}
