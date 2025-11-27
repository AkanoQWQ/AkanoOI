#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 18;
const int MAXS = (1<<6) + 10 + 18;
const int MAXM = 506;
const int MAXLEN = 106;
string s[MAXN],str;
int n,m;
inline string F(const string& str){
	string ret = str;
	for(auto& i : ret){
		i = (!(i - '0')) + '0';
	}
	return ret;
}
inline bool Include(const string& u,const string& v){
	return u.find(v) < u.length();
}
inline bool Calc(){
	string nxt = F(str);
	reverse(nxt.begin(),nxt.end());
	const string now = str + nxt;
	for(int i = 1;i <= n;i++){
		if(Include(now,s[i]) == false)return false;
	}
	return true;
}
int dfs(int u){
	if(u > m){
		return Calc();
	}
	int ret = 0;
	str += '0';
	ret += dfs(u+1);
	str.pop_back();
	str += '1';
	ret += dfs(u+1);
	str.pop_back();
	return ret;
}
ll p2[MAXM];
inline ll N1(){
	ll ret = 0;
	const int len = s[1].length();
	string s1 = "." + s[1];
	p2[0] = 1;
	for(int i = 1;i <= m;i++)p2[i] = (p2[i-1] * 2) % MOD;
	if(m >= len){
		ret += p2[m - len]*(m-len)*2;//可能泉在左边或者右边
//		cerr<<"base "<<p2[m - len]<<endl;
	}
	for(int i = len;i >= 1;i--){//i及以后泉部算右边
		bool OK = true;
		for(int j = 1;i+j-1 <= len && i-j >= 1;j++){
			if(s1[i+j-1] == s1[i-j]){
//				cerr<<"pos "<<i<<" fail in "<<i+j-1<<" and "<<i-j<<endl;
				OK = false;
			}
		}
		const int res = max(i-1,len-i+1);
		if(OK && m >= res){
//			cerr<<"got "<<p2[m - res]<<" in pos "<<i<<endl;
			ret += p2[m - res];
		}
	}
	
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	cout<<dfs(1)<<endl;
	return not(Akano loves pure__Elysia);
}
