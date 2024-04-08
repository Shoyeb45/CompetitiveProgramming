#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int hour  = (s[0] - '0') * 10 + (s[1] - '0');
        int min = (s[3] - '0') * 10 + (s[4] - '0');
        string time = "";
        string hr;
        string minute;
        if(hour >= 1 && hour < 12) {
            time = "AM";
        } else if(hour == 0){
            time = "AM";
            hour = 12;
        } else if(hour == 12) {
            time = "PM";
            hr = "12";
        } else {
            hour = hour - 12;
            time = "PM";
        }
            if(!(hour/10)) { 
                hr = "0";
                hr += to_string(hour);
            } else {
                hr = to_string(hour);
            }

        if(!(min/10)) {
            minute = "0";
            minute += to_string(min);
        } else {
            minute = to_string(min);
        }
        cout << hr + ":" + minute + " " + time << endl;
    }
    
}
