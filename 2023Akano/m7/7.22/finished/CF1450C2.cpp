#include<bits/stdc++.h>
using namespace std;
const int MAXN = 306;
int t,n;
char mp[MAXN][MAXN],orgmp[MAXN][MAXN];
inline int Calc(char from,char to,int change){
	int ret = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if((i+j)%3 == change)ret += (mp[i][j] == from);
		}
	}
	return ret;
}
inline void Change(char from,char to,int change){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(((i + j) % 3 == change) && (mp[i][j] == from)){
				mp[i][j] = to;
			}
		}
	}
	return ;
}
inline void Solve(){
	cin>>n;
	int k = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>mp[i][j];
			k += (mp[i][j] != '.');
		}
	}
	bool BRK = false;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(i == j)continue;
			int usek = Calc('X','O',i) + Calc('O','X',j);
			if(usek <= (k / 3)){
//				cout<<i<<","<<j<<" use "<<usek<<endl;
				Change('X','O',i);
				Change('O','X',j);
				BRK = true;
				break;
			}
		}
		if(BRK)break;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
//	cout<<flush;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("C2.in","r",stdin);
	cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}
