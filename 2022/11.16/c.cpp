#include<bits/stdc++.h>
using namespace std;
int t,l,r,x,a,b;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		bool gotl_1 = 0,gotr_1 = 0,gotl_2 = 0,gotr_2 = 0;
		cin>>l>>r>>x>>a>>b;
		if(a == b){
			puts("0");
			continue;
		}
		if(abs(a-b) >= x){
			puts("1");
			continue;
		}
		if(abs(a - l) >= x){
			gotl_1 = 1;
			if(abs(l-b) >= x){
				puts("2");
				continue;
			}
		}
		if(abs(r - a) >= x){
			gotr_1 = 1;
			if(abs(r-b) >= x){
				puts("2");
				continue;
			}
		}
		if(gotl_1 && abs(r-l) >= x){
			if(abs(r-b) >= x){
				puts("3");
				continue;
			}
		}
		if(gotr_1 && abs(r-l) >= x){
			if(abs(l-b) >= x){
				puts("3");
				continue;
			}
		}
		puts("-1");
	}
	return 0;
}

