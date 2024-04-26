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
        int pos[26] = {0};
        for(char & ch : s) {
            int idx = ch - 'a';
            pos[idx]++;
        }
            
        auto mxOccurenece = *max_element(pos, pos + 26);
        int position = 0;
        for(int i = 0 ; i < 25; i++) 
            if(pos[i] == mxOccurenece)
                position = i;

        char maxOcc = position + 'a';
        cout << maxOcc << "\n";
    
    
    return 0;
}
