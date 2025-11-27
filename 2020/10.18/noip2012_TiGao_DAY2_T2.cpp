#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int maxn = 1000000+100;
int n,m,i,j;
ll r[maxn],d[maxn],s[maxn],t[maxn];
ll cf[maxn],sum[maxn];;

bool calc(int mid){
	memset(cf,0,sizeof(cf));
	memset(sum,0,sizeof(cf));
	for(i = 1;i <= mid;i++){
		cf[s[i]] += d[i];
		cf[t[i]+1] -= d[i];
	}
	for(i = 1;i <= n;i++){
		sum[i] = sum[i-1]+cf[i];
	}
	bool canbe = 1;
	for(i = 1;i <= n;i++){
		if(sum[i] > r[i]){
			canbe = false;
		}
	}
	return canbe;
}
int main(){3.


	cin>>n>>m;
	for(i = 1;i <= n;i++){
		cin>>r[i];
	}
	ll dd,ss,tt;
	for(i = 1;i <= m;i++){
		cin>>dd>>ss>>tt;
		d[i] = dd;
		s[i] = ss;
		t[i] = tt;
	}
	int L = 0,R = m;
	while(L<R){
		int mid = (L+R+1)>>1;
		if(calc(mid)){
			L = mid;
		}else{
			R = mid - 1;
		}
	}
	if(L == m){
		cout<<0<<endl;
	}else{
		cout<<-1<<endl<<L+1<<endl;
	}
	return 0;
}
