#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    int reversePair(vector<ll>&v1,vector<ll>&v2){
        int c=0,i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if((v1[i]/2)>(2*v2[j])){c+=v1.size()-i;j++;}
            else i++;
        }
        return c;
    }
    void mergeTwoArrays(vector<ll>&v1,vector<ll>&v2,vector<ll>&v){
        int i=0,j=0,k=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]) v[k++]=v1[i++];
            else v[k++]=v2[j++];
        }
        if(i==v1.size()) while(j<v2.size()) v[k++]=v2[j++];
        else while(i<v1.size()) v[k++]=v1[i++];
    }
    int mergeSort(vector<ll>&v){
        ll count=0,n1=v.size()/2,n2=v.size()-n1;
        if(v.size()==1) return 0;
        vector<ll>v1(n1),v2(n2);

        for(int i=0;i<n1;i++) v1[i]=v[i];
        for(int i=0;i<n2;i++) v2[i]=v[i+n1];
        count+=mergeSort(v1);
        count+=mergeSort(v2);

        count+=reversePair(v1,v2);

        mergeTwoArrays(v1,v2,v);
        v1.clear();
        v2.clear();
        return count;
    }
int main()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<mergeSort(nums);
    return 0;
}