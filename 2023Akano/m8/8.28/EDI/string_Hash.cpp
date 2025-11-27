#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using ull = unsigned long long;
bool ST;
const int MAXN = 2e6 + 1018 + 1108;
const int stp = 31;
const int SIZE2 = 1e4;
const int MX_OMG = 1e7;
ll stps[MAXN];
ull hs[MAXN],cnt;
struct MyHash{
	int st,ed,tail;
	inline void PushBack(char ch){
		hs[tail] = hs[tail-1] * stp + ch - 'a';
		tail++;
		return ;
	}
	inline void SetString(const string& str){
		st = cnt + 2,ed = st + str.length() - 1;
		tail = st;
		for(auto i : str)PushBack(i);
		cnt = ed;
		return ;
	}
	inline int len(){
		return ed - st + 1;
	}
	inline ull Cut(int l,int r){
		l += st-1,r += st-1;
		return hs[r] - (hs[l-1] * stps[r-l+1]);
	}
}mh[MAXN];
int n,q,mxlen;
inline void Init(){
	stps[0] = 1;
	for(int j = 1;j <= mxlen+3;j++){
		stps[j] = stps[j-1] * stp;
	}
	return ;
}
int blk,ans[SIZE2][SIZE2],dir[MAXN],arr[MAXN];
inline int Calc(int u,int v){
	const int len = mh[u].len(),up = min(len,mh[v].len());
	int res = 0;
	for(int i = up;i >= 1;i--){
		if(mh[u].Cut(len-i+1,len) == mh[v].Cut(1,i)){
			res = i;
			break;
		}
	}
	return res;
}
inline void Solve(){
	blk = sqrt(mxlen)*16;//16是什么神奇参数?! 
	vector<int> vec;
	for(int i = 1;i <= n;i++)dir[i] = -1;
	for(int i = 1;i <= n;i++){
		if(int(vec.size() >= SIZE2-2)){
			break;
		}
		if(mh[i].len() >= blk){
			dir[i] = vec.size();
			vec.push_back(i);
		}
	}
	for(int i = 0;i < int(vec.size());i++){
		for(int j = 0;j < int(vec.size());j++){
			ans[i][j] = Calc(vec[i],vec[j]);
		}
	}
	return ;
}
bool ED;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		string str;
		cin>>str;
		mh[i].SetString(str);
		mxlen = max(mxlen,mh[i].len());
	}
	Init();
	Solve();
	while(q--){
		int u,v,res;
		cin>>u>>v;
		if(dir[u] != -1 && dir[v] != -1){
			res = ans[dir[u]][dir[v]];
		}else{
			res = Calc(u,v);
		}
		cout<<res<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
