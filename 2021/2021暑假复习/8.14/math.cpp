#include<bits/stdc++.h>
using namespace std;
int a[10],i,ans;
bool comp(int b,int c){
	return b>c;
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3,comp);
	ans = (a[0]*10) + a[1] + a[2];
	cout<<ans;
	return 0;
} 
