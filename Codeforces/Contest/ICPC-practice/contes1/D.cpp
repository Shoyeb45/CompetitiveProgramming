#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> names(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> names[i];
    }

    vector<string> sequences(M);
    unordered_map<string, int> mp[6];
    int n = 1;
    for(int i = 0; i < n && n < 6; i++) {
        string temp = "";
        for(auto s: names) {
            for(int j = 0)
        }
    }


    for (int i = 0; i < M; ++i) {
        cin >> sequences[i];
    }

    unordered_map<char, string> runeMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

  
    for(string seq : sequences) {
        int cnt = 0;
        for(char i: seq) {

        }
    }
    return 0;
}
