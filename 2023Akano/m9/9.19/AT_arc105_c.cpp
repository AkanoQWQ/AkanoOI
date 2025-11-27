#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 12;
const int MAXM = 1e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;
int n,m,w[MAXN],a[MAXN],num[MAXN],dis[MAXN],ans = INF,mxw,mnv = INF;
struct Bridge{
	mutable int len,val;
	Bridge() = default;
	Bridge(int _len,int _val){
		len = _len,val = _val;
		return ;
	}
};
bool operator<(Bridge b1,Bridge b2){
	if(b1.val != b2.val)return b1.val < b2.val;
	return b1.len > b2.len;
}
set<Bridge> st;
inline int Solve(){
	for(int i = 2;i <= n;i++){
		dis[i] = dis[i-1];
		int sumw = a[i];
		for(int j = i-1;j >= 1;j--){
			sumw += a[j];
			int len = (--st.upper_bound(Bridge(INF,sumw)))->len;
			dis[i] = max(dis[i],dis[j] + len);
		}
	}
	return dis[n];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>w[i];
		mxw = max(mxw,w[i]);
	}
	st.insert(Bridge(0,0));
	for(int i = 1;i <= m;i++){
		int l,v;
		cin>>l>>v;
		st.insert(Bridge(l,v));
		mnv = min(mnv,v);
	}
	for(auto it = st.begin();it != st.end();it++){
		auto pre = it;
		if(it != st.begin()){
			pre--;
			it->len = max(it->len,pre->len);
		}
	}
	if(mxw > mnv){
		cout<<-1<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(int i = 1;i <= n;i++)num[i] = i;
	do{
		for(int i = 1;i <= n;i++)a[i] = w[num[i]];
		ans = min(ans,Solve());
	}while(next_permutation(num+1,num+n+1));
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
/*
n! : Ã¶¾ÙË³Ðò		4e4
 

*/
