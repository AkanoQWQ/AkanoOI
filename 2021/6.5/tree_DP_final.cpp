#include<bits/stdc++.h>
using namespace std;
const int N = 500005 * 2,M = 500005 * 4;
int i,j,next[M],first[M],v[M],w[M],t,n,m,p,ans,d[M],x,y,z,f1[M],f2[M];
void add(int x,int y,int z){
	next[++t] = first[x];
	first[x] = t;
	v[t] = y;
	w[t] = z;
}



void dp(int x,int father){
	for(i = first[x];i;i = next[i]){
		int j = v[i];
		if(j == father) continue;
		dp(j,x);
		if(f1[x] < f1[j] + w[i]){
			f2[x] = f1[x];
			f1[x] = f1[j] + w[i];
		}else if(f2[x] < f1[j] + w[i]){
			f2[x] = f1[j] + w[i];
		}
		ans = max(ans,(f1[x] + f2[x]));
	}
}
int main(){
	//freopen("treedp.in","r",stdin);
	//freopen("treedp.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dp(1,0);
	cout<<ans;
	return 0;
}

