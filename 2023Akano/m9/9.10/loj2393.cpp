#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int n,m,ans,ticket[MAXN];
inline int QueryForward(int u,int v){
	int ret = 0;
	if(u <= v){
		for(int i = u;i < v;i++)ret = max(ret,ticket[i]);
	}else{
		for(int i = u;i <= n;i++)ret = max(ret,ticket[i]);//u -> 1
		for(int i = 1;i < v;i++)ret = max(ret,ticket[i]);//1 -> v
	}
	return ret;
}
inline int QueryReverse(int u,int v){
	int ret = 0;
	if(u <= v){
		for(int i = u-1;i >= 1;i--)ret = max(ret,ticket[i]);//u -> 1
		for(int i = n;i >= v;i--)ret = max(ret,ticket[i]);//1 -> v
	}else{
		for(int i = u-1;u >= v;i--)ret = max(ret,ticket[i]);
	}
	return ret;
}
inline int AddForward(int u,int v){
	int ret = 0;
	if(u <= v){
		for(int i = u;i < v;i++)ticket[i]++;
	}else{
		for(int i = u;i <= n;i++)ticket[i]++;//u -> 1
		for(int i = 1;i < v;i++)ticket[i]++;//1 -> v
	}
	return ret;
}
inline int AddReverse(int u,int v){
	int ret = 0;
	if(u <= v){
		for(int i = u-1;i >= 1;i--)ticket[i]++;//u -> 1
		for(int i = n;i >= v;i--)ticket[i]++;//1 -> v
	}else{
		for(int i = u-1;u >= v;i--)ticket[i]++;
	}
	return ret;
}
set<pair<int,int> > st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans += c / 2;
		c &= 1;
		if(c == 0)continue;
		st.insert(make_pair(a,b));
	}
	while(!st.empty()){
		ans++;
		vector<pair<int,int> > del;
		int st = 
	}
	return not(Akano loves pure__Elysia);
}
