#include<bits/stdc++.h>
using namespace std;
int n,a[200611],l,r,opt = 0;
int rbig(int l,int r,int k){
	return (a[l] > k) && (a[r] > k);
}
int rsml(int l,int r,int k){
	return (a[l] <= k) && (a[r] <= k);
}
string judge(int x){
	for(int i = 0;i < n-1;i++){
		if(rbig(n-i,n-i-1,x) || rbig(n+i,n+i+1,x)){
			return "big";
		}
		if(rsml(n-i,n-i-1,x) || rsml(n+i,n+i+1,x)){
			return "small";
		}
	}
	if(rsml(1,1,x)){
		return "small";
	}else{
		return "big";
	}
}
int main(){
	freopen("hard.in","r",stdin);
	freopen("hard.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= 2*n-1;i++){
		cin>>a[i];
	}
	int l = 1,r = 2*n-1;
	while(l < r){
		int mid = (l + r) >> 1;
		string res = judge(mid);
		if(res == "small"){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	cout<<r;
	return 0;
}
