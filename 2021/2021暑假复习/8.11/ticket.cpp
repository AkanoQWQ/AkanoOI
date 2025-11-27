#include<bits/stdc++.h>
using namespace std;
long long n,m,pos[1000006],i,j,s,t,w,c,ans;
int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i < m;i++){
		cin>>c;
		pos[i] = pos[i-1]+c;
	}//3 8
	//1-2:3  2-3:5
	for(i = 0;i < n;i++){
		cin>>s>>t>>w;
		ans += (pos[t-1]-pos[s-1]) * w;
	}
	cout<<ans;
	return 0;
}

