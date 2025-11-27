#include<bits/stdc++.h>
using namespace std;
int n,t;
struct obj{
	int m,v;
	double vdm;//v divide m
}o[2006];
bool cmp(obj a,obj b){
	return a.vdm  > b.vdm;
}
double ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>t;
	for(int i = 1;i <= n;i++){
		cin>>o[i].m>>o[i].v;
		o[i].vdm = double(o[i].v) / double(o[i].m);
	}
	sort(o+1,o+1+n,cmp);
	for(int i = 1;i <= n;i++){
		if(t >= o[i].m){
			t -= o[i].m;
			ans += o[i].v;
		}else{
			ans += t * o[i].vdm;
			t = 0;
		}
	}
	printf("%.2f",ans);
	return 0;
}

