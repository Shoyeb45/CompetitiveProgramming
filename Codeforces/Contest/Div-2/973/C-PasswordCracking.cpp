#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;

bool ask(string s) {
    printf("? %s\n", s.c_str());  
    fflush(stdout);               

    int res;
    scanf("%d", &res);      
    if(res == -1) {
        exit(0);
    }      
    return res;
}

// char remString(string s) {
//     string temp = s;
//     temp += '0';                   
//     int a1 = ask(temp);
    
//     temp = s;
//     temp += '1';
//     int a2 = ask(temp);

//     if (a1 == 1) {                 
//         return '0';
//     }
//     return '1';                    
// }

void solve() {
    scanf("%d", &n);                
    string ans = "";
    
    while (ans.size() < n) {
        if(ask(ans + "0")) {
            ans += '0';
            continue;
        }
        if(ask(ans + "1")) {
            ans += '1';
            continue;
        }
        break;
    }

    while (ans.size() < n) {
        if(ask("0" + ans)) {
            ans = '0' + ans;
            continue;
        }
        else {
            ans = '1' + ans;
            continue;
        }
        break;
    }

    printf("! %s\n", ans.c_str());  
    fflush(stdout);                 
}

int main() {
    int tt;
    scanf("%d", &tt);              

    while (tt--) {
        solve();                    
    }

    return 0;
}
