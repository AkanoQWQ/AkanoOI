#include<bits/stdc++.h>
using namespace std;
const int MAXN = 66;
int t,m,s,a[MAXN],sum,bg;
int tong[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>m>>s;
		memset(tong,0,sizeof(tong));
		sum = 0,bg = 0;
		bool able = 1;
		for(int i = 1;i <= m;i++){
			cin>>a[i];
			tong[a[i]]++;
			bg = max(bg,a[i]);
		}
		for(int i = 1;i <= bg;i++){
			if(tong[i] == 0){
				s -= i;
			}else if(tong[i] > 1){
				able = 0;
			}
		}
		while(s > 0){
			s -= ++bg;
		}
		if(s < 0){
			able = 0;
		}
		if(able == 0){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}
