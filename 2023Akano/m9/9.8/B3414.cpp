#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using Integer = __int128; 
const Integer MOD = 1843871216889928417;//抄的模数ww 
const int MAXN = 206;
istream& operator>>(istream& is,Integer& inte){
	string str;
	cin>>str;
	inte = 0;
	for(auto i : str){
		inte = (inte * 10 + i - '0') % MOD; 
	}
	return is;
}
ostream& operator<<(ostream& os,Integer inte){
	string str = "";
	while(inte){
		str += char((inte % 10) + '0');
		inte /= 10;
	}
	reverse(str.begin(),str.end());
	cout<<str;
	return os;
}
int n;
Integer table[MAXN][MAXN];//记得范围要取到n+1来更新ans
inline Integer KSM(Integer a,Integer b){
	Integer ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline Integer Div(Integer a,Integer b){
	return (a * KSM(b,MOD-2)) % MOD;
}
inline void Solve(){
	for(int now = 1;now <= n;now++){
		int mx = now;
		for(int i = now;i <= n;i++){
			if(table[i][now] > table[mx][now])mx = i;
		}
		if(mx != now)swap(table[mx],table[now]);
		for(int i = n+1;i >= now;i--){//倒序防止div值被修改 
			table[now][i] = Div(table[now][i],table[now][now]);
		}
		for(int i = 1;i <= n;i++){
			if(i == now)continue;
			for(int j = n+1;j >= now;j--){
				table[i][j] = (table[i][j] - ((table[now][j] * table[i][now]) % MOD)) % MOD;
				table[i][j] = (table[i][j] + MOD) % MOD;
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n+1;j++){
			cin>>table[i][j];
		}
	}
	Solve();
	for(int i = 1;i <= n;i++){
		cout<<Div(table[i][n+1],table[i][i])<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
