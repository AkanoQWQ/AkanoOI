#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 200006;
const ll MOD = 10000;
struct staco{
	ll tp,c[MAXN];
	inline void pop(){
		--tp;
	}
	inline void push(int inx){
		c[++tp] = inx;
	}
	inline ll top(){
		return c[tp];
	}
	inline bool empty(){
		return (tp == 0);
	}
	inline ll size(){
		return tp;
	}
}sta;
string s;
ll inn,ans;
int main(){
//	freopen("P1981.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.length();i++){
		if(s[i] == '+'){
			if(sta.top() == -2){
				sta.pop();
				const int u = sta.top();
				sta.pop();
				sta.push((inn * u) % MOD);
			}else{
				sta.push(inn);
			}
			sta.push(-1);
			inn = 0;
		}else if(s[i] == '*'){
			if(sta.top() == -2){
				sta.pop();
				const int u = sta.top();
				sta.pop();
				sta.push((inn * u) % MOD);
			}else{
				sta.push(inn);
			}
			sta.push(-2);
			inn = 0;
		}else{
			inn = inn * 10 + s[i] - '0';
			inn %= MOD;
		}
	}
	sta.push(inn);
	while(sta.size() > 1){
		const int u = sta.top();
		sta.pop();
		const int opt = sta.top();
		sta.pop();
		const int v = sta.top();
		sta.pop();
		if(opt == -1){
			sta.push((u+v)%MOD);
		}else{
			sta.push((u*v)%MOD);
		}
	}
	printf("%lld",sta.top() % MOD);
	return 0;
}
