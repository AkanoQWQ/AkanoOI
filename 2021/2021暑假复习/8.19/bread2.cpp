#include<bits/stdc++.h>
using namespace std;
const int maxn = 100006;
long long n,k,x[maxn],y[maxn];
bool USED[maxn];//
int dp(long long t,bool u[],long long usage,int tk){
	long long a = 0,b = 0;
	bool c = 0;
	if(t == n || usage == k)return 0;
	a = dp(t+1,u,usage,tk);
	if(u[x[t]] == 0){
		u[x[t]] = 1;
		c = 1;
		b = dp(t+1,u,usage+1,tk+1) + y[t] + ((tk+1)*(tk+1)-(tk*tk));
	}else{
		b = dp(t+1,u,usage+1,tk) + y[t];
	}
	cout<<t<<" "<<a<<" "<<b<<" "<<usage<<" "<<tk<<" "<<c<<endl; 
	return max(a,b);
}
int main(){
	freopen("bread.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i < n;i++)cin>>x[i]>>y[i];
	cout<<dp(0,USED,0,0);
	return 0;
}

