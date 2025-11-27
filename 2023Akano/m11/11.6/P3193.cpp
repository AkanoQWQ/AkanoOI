#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1018 + 1108;
const int MAXM = 106;
int MOD = 1e9 + 7;
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int len,mtxUP;
struct Matrix{
	ll c[MAXM][MAXM];
	Matrix(){
		memset(c,0,sizeof(c));
		return ;
	}
	Matrix(int x){
		memset(c,0,sizeof(c));
		for(int i = 0;i <= len+1;i++){
			c[i][i] = x;
		}
		return ;
	}
	ll* operator[](int x){
		return c[x];
	}
	const ll* operator[](int x)const{
		return c[x];
	}
};
Matrix opt,ans;
Matrix operator*(const Matrix& mtx1,const Matrix& mtx2){
	Matrix ret;
	for(int i = 0;i <= mtxUP;i++){
		for(int j = 0;j <= mtxUP;j++){
			for(int k = 0;k <= mtxUP;k++){
				ret[i][j] = (ret[i][j] + mtx1[i][k] * mtx2[k][j]) % MOD;
			}
		}
	}
	return ret;
}
Matrix MTXKSM(Matrix a,ll b){
	Matrix ret(1);
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
class ACautomaton{
private:
	int nxt[MAXM][27],fail[MAXM],tot;
	bool flag[MAXM];
public:
	inline void Insert(const string& str){
		int u = 0;
		for(auto ch : str){
			const int i = ch - '0';
			if(nxt[u][i] == 0)nxt[u][i] = ++tot;
			u = nxt[u][i];
		}
		flag[u] = true;
		return ;
	}
	inline void Build(){
		queue<int> q;
		for(int i = 0;i < 26;i++){
			if(nxt[0][i] != 0){
				q.push(nxt[0][i]);
			}
		}
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			flag[u] |= flag[fail[u]];//OK????
			for(int i = 0;i < 26;i++){
				if(nxt[u][i]){
					fail[nxt[u][i]] = nxt[fail[u]][i];
					q.push(nxt[u][i]);
				}else{
					nxt[u][i] = nxt[fail[u]][i];
				}
			}
		}
		return ;
	}
	inline int Size(){
		return tot;
	}
	inline bool Judge(int x){
		return flag[x];
	}
	inline int GetNext(int u,int x){
		return nxt[u][x];
	} 
}aca;
int n,m;
string nows;
inline ll Solve(){
	len = aca.Size();
	mtxUP = len + 1;
	for(int u = 0;u <= len;u++){
		for(int ch = 0;ch < 10;ch++){
			const int nxt = aca.GetNext(u,ch);
			if(aca.Judge(nxt)){
				opt[u][mtxUP]++;
			}else{
				opt[u][nxt]++;
			}
		}
	}
	opt[mtxUP][mtxUP] = 10;
	ans[1][0] = 1;
	ans = ans * MTXKSM(opt,n);
	return ans[1][mtxUP];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("str.in","r",stdin);
//	freopen("str.out","w",stdout);
	cin>>n>>len>>MOD>>nows;
	aca.Insert(nows);
	aca.Build();
	ll finalans = KSM(10,n);
	finalans = (((finalans - Solve()) % MOD) + MOD) % MOD;
	cout<<finalans<<endl;
	return not(Akano loves pure__Elysia);
}
