#include<bits/stdc++.h>
using namespace std;

int n;

int ask(string s) {
    printf("? %s\n", s.c_str());  
    fflush(stdout);               

    int res;
    scanf("%d", &res);            
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
        string temp = ans;
        if(ask(temp + "0")) {
            ans += '0';
            continue;
        }

        if(ask(temp + "1")) {
            ans += '1';
            continue;
        }
    }

    while (ans.size() < n) {
        string temp = ans;
        if(ask("0" + temp)) {
            ans = '0' + ans;
            continue;
        }

        if(ask("1" + temp)) {
            ans = '1' + ans;
            continue;
        }
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
