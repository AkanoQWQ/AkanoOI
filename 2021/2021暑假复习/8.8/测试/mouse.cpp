#include<bits/stdc++.h>
using namespace std;
const int maxn = 108964;//20000000  200
int n,i,d[5064],used[maxn];
struct mouse{
	int t,v;
}m[maxn];
bool comp(mouse a,mouse b){
	return a.t < b.t;
}
int dp(int t,int u[]){
	int cnt = 0,ans = 0,tail = 0,cache = 0;
	while(tail < n){
		if(m[tail].t >= t&&u[tail] == 0){
			u[tail] = 1;
			cnt = dp(t+1,u) + m[tail].v;
			u[tail] = 0;
			if(cnt > ans){
				ans = cnt;
				cache = tail;
			}
		}
		tail++;
	}
	return ans;
}
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>m[i].t;
	}
	for(i = 0;i < n;i++){
		cin>>m[i].v;
	}
	sort(m,m+n,comp);
	cout<<dp(1,used);
	return 0;
}

