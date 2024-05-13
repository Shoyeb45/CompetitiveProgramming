#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void showdq(deque<int> g)
{
    
    for (auto it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    deque<int> dq;
    // Pushing at last
    dq.push_back(12); // {12}
    dq.push_back(14); // {12, 14}
    dq.push_back(20); // {12, 14, 20}

    // Access in first and last
    cout << dq.front() << '\n'; // 12
    cout << dq.back() << '\n'; // 20

    // Pushing at front
    dq.push_front(-12); // {-12, 12, 14, 20}
    cout << dq.front() << '\n';

    dq.push_front(-20); // {-20, -12, 12, 14, 20}
    cout << dq.front() << '\n';

    // Removing element
    dq.pop_back(); // {-20, -12, 12, 14}
    dq.pop_front(); // {-12, 12, 14}
    cout << dq.size() << '\n';
    cout << "Front: " << dq.front() << '\n';
    cout << "Back: " << dq.back() << '\n';
    return 0;
}
