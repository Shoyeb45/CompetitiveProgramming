#include<bits/stdc++.h>
using namespace std;

int main() {
        int n;
        int m;
        cin >> n ;
        int arr1[n];
        for(int i = 0; i<=n-1; i++){
            cin >> arr1[i];
        }

        cin >> m;
        int arr2[m];
        for(int i = 0; i<=m-1; i++){
            cin >> arr2[i];
        }

        int c[n+m];

        int k = 0;
        for(int i = 0, j = 0 ; i < n || j < m ;){
            if(i == n){
            c[k] = arr2[j];
            k++;
            j++;
        }
            else if(j == m) {
            c[k] = arr1[i];
            k++;
            i++;
        }
            else if(arr1[i] <= arr2[j]) {
            c[k] = arr1[i];
            k++;
            i++;
        }
            else {
            c[k] = arr2[j];
            k++;
            j++;
        }
        }
        for(int i= 0; i<=n+m-1; i++){
            cout << c[i] << " ";
        }
    } 
