#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

struct node {
    int data;
    int next;
};
int main() {
    struct node list[10];
    // int a[10][2];
    list[5].data = 3;
    list[5].next = 2;
    list[list[5].next].data = 1;
    list[list[5].next].next = 8;

    list[list[list[5].next].next].data = 7;
    list[list[list[5].next].next].next = -1;
    printf("First element: %d\n",list[5].data);
    printf("Second element: %d\n", list[list[5].next].data );
    printf("Third element: %d\n", list[list[list[5].next ].next].data );
    
    return 0;
}
