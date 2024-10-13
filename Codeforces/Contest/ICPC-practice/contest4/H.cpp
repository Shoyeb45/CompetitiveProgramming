#include<bits/stdc++.h>
//vivaanpc
using namespace std;
//vivaanpc
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	int temp = a * b;
	for (int i = 1; i <= 9; i++) {
		cout << (temp * i + 9) / 10 << " ";
	}
	return 0;
}