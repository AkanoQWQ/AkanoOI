#include<bits/stdc++.h>
using namespace std;
int n,a[200611],l,r,opt = 0;
string judge(int x){
	for(int i = 1;i <= n*2+1;i++){
		if(i%2==(n%2==0)){//С 
			
		}else{
			
		}
	}
}
int main(){
	freopen("hard.in","r",stdin);
	//freopen("hard.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= 2*n-1;i++){
		cin>>a[i];
	}
	int l = 1,r = 2*n-1;
	while(l <= r){
		int mid = (l + r) >> 1;
		string res = judge(mid);
		if(res == "big"){
			r = mid + 1;
		}else if(res == "small"){
			l = mid + 1;
		}else if(res == "OK"){
			cout<<mid;
			return 0;
		}
	}
	return 0;
}
