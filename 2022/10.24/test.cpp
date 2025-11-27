#include<bits/stdc++.h>
using namespace std;
long long x,k;
int sz[3]={1,2};
int main(){
    cin>>x>>k;
    while(1){
        x++;
        if(x%3==0) x/=3;
        k--;
        if(k==0) break;
        if(x==3) break;
    }
    if(k==0) cout<<x;
    else cout<<sz[k%2];
    return 0;
}
