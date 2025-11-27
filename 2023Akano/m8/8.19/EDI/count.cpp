#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXW = 66;
int q;
int delta[MAXW],num[MAXW],dlen,nlen;
inline void Trans(ll x,int& len,int arr[]){
	len = 0;
	while(x){
		arr[++len] = x % 3;
		x /= 3;
	}
	for(int i = len+1;i < MAXW;i++)arr[i] = 0;
	return ;
}
ll f[MAXW][2];
ll dfs(ll pos,bool up,bool limit){
	if(pos == 0)return (up == false);
	if(f[pos][up] != -1 && !limit)return f[pos][up];
	ll ret = 0;
	int upper = limit ? num[pos] : 2;
	//下一位要进位 
	for(int i = 0;i <= upper;i++){
		int real = i + delta[pos] + 1;
		if(real / 3 != up)continue;//本位的进位 
		real %= 3;
		if(real % 2 == i % 2){
			ret += dfs(pos-1,true,limit & (i == upper));
		}
	}
	//下一位不进位 
	for(int i = 0;i <= upper;i++){
		int real = i + delta[pos];
		if(real / 3 != up)continue;//本位的进位 
		real %= 3;
		if(real % 2 == i % 2){
			ret += dfs(pos-1,false,limit & (i == upper));
		}
	}
	if(!limit)f[pos][up] = ret;
	return ret;
}
inline ll Solve(ll x){
	if(x < 0)return 0;
	Trans(x,nlen,num);
	int len = max(nlen,dlen);
	memset(f,-1,sizeof(f));
	return dfs(len,false,true);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>q;
	for(int i = 1;i <= q;i++){
		ll d,x,y,ret = 0;
		cin>>d>>x>>y;
		if(x > y)swap(x,y);
		Trans(y-x,dlen,delta);
		ret += Solve(x+d) - Solve(x-1);
		cout<<ret<<'\n';
	}
	return 0;
}
