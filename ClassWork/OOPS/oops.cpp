#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// Creating class
class Fruit {
    public:
        // Creating attributes
        string name;
        string color;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Creating object
    Fruit f1;
    f1.name = "Mango";
    f1.color = "Yello";

    cout << f1.name << " " << f1.color << "\n";

    // Another way using new keyword
    Fruit *f2 = new Fruit();
    f2->name = "Banana";
    f2->color = "Yellow";
    cout << f2->name << " " << f2->color << "\n";


    return 0;
}
