#include<bits/stdc++.h>
using namespace std;
int n,a[25],x,cx,c[25],d[25],cc[25],ans;
int main(){
	freopen("t2.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		c[i] = i;
	}
	if(n <= 9){
		do{
			int cx = x;
			for(int i = 1;i <= n;i++){
				cx %= a[c[i]];
			}
			
			if(cx > ans){
				for(int j = 1;j <= n;j++){
					cc[j] = c[j];
				}
			}
			ans = max(ans,cx);
		}while(next_permutation(c+1,c+n+1));
	}else{
		for(int i = n;i >= (n-7);i--){
			d[i] = i;
		}
		int nx = x;
		do{
	//		for(int i = n-7;i <= n;i++){
	//			cout<<d[i]<<" ";
	//		}
	//		cout<<endl;
			int cx = x;
			for(int i = n-7;i <= n;i++){
				cx %= a[d[i]];
			}
			for(int i = n-8;i >= 1;i--){
				cx %= a[i];
			}
			if(cx > ans){
				for(int j = 1;j <= n;j++){
					cc[j] = c[j];
				}
			}
			ans = max(ans,cx);
		}while(next_permutation(d+n-7,d+n+1));
	}
	cout<<ans;
	return 0;
}

