#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

// defining class

class Student {
    public:
        string name;
        string subject;
        int marks;
};

int main() {
    Student stud1;
    stud1.name = "Shoyeb";
    stud1.subject = "Maths";
    stud1.marks = 90;

    cout << stud1.name  << endl << stud1.subject << endl <<  stud1.marks;
}
