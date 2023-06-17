#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i; cin>>n;
    int x[2*n];
    for(i=0;i<2*n;i++) cin>>x[i];
    sort(x,x+2*n);
    cout<<1LL*(x[n-1]-x[0])*(x[2*n-1]-x[n]);
    return 0;
}