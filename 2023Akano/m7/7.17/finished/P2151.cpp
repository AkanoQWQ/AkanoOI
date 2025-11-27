#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXM = (10 + 18 + 11 + 8 + 27) * 2;
const int MOD = 45989;
pii e[MAXM];
int n,m,ST,ED,t,sz,cnt = 1;
struct Matrix{
	int c[MAXM][MAXM];
	int* operator[](int _x){
		return c[_x];
	}
	Matrix(){memset(c,0,sizeof(c));return ;}
	Matrix(int val){
		memset(c,0,sizeof(c));
		for(int i = 1;i <= sz;i++)c[i][i] = val;
		return ;
	}
};
ostream& operator<<(ostream& cout,Matrix cm){
	for(int i = 1;i <= sz;i++){
		for(int j = 1;j <= sz;j++){
			cout<<cm[i][j]<<" ";
		}
		cout<<endl;
	}
	return cout;
}
Matrix operator*(Matrix ma,Matrix mb){
	Matrix ret;
	for(int i = 1;i <= sz;i++){
		for(int j = 1;j <= sz;j++){
			for(int k = 1;k <= sz;k++){
				ret[i][j] = (ret[i][j] + ma[i][k] * mb[k][j]) % MOD;
			}
		}
	}
	return ret;
}
inline Matrix KSM(Matrix ma,int b){
	Matrix ret = Matrix(1);
	while(b){
		if(b & 1)ret = ret * ma;
		ma = ma * ma;
		b >>= 1;
	}
	return ret;
}
Matrix opt,org;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2151_2.in","r",stdin);
	cin>>n>>m>>t>>ST>>ED;
	ST++,ED++;
	while(m--){
		int u,v;
		cin>>u>>v;
		u++,v++;
		e[++cnt] = {u,v},e[++cnt] = {v,u};
	}
	e[++cnt] = {0,ST};
	sz = cnt;
 	for(int i = 2;i <= cnt;i++){
		for(int j = 2;j <= cnt;j++){
			if(j == (i^1))continue;
			if(e[j].first == e[i].second){
				opt[i][j]++;
			}
		}
	}
	org[1][cnt] = 1;
	Matrix mans = org * KSM(opt,t);
	int ans = 0;
	for(int i = 1;i <= cnt;i++){
		if(e[i].second == ED){
			ans = (ans + mans[1][i]) % MOD;
		}
	}
	cout<<ans;
	return 0;
}

