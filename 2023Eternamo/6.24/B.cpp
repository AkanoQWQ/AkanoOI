#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int t,n,x,a[MAXN],b[MAXN],c[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>x;
		int now = 0;
		bool AOK = 1,BOK = 1,COK = 1;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(AOK){
				if((now | a[i] | x) == x){
					now |= a[i];
				}else{
					AOK = 0;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			cin>>b[i];
			if(BOK){
				if((now | b[i] | x) == x){
					now |= b[i];
				}else{
					BOK = 0;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			cin>>c[i];
			if(COK){
				if((now | c[i] | x) == x){
					now |= c[i];
				}else{
					COK = 0;
				}
			}
		}
		if(now == x){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

