#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10 + 18 + 11 + 8;
int a,b,n = 100,m = 100;
int split = m/2;
bool swp;
char mp[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	--a,--b;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= split;j++){
			mp[i][j] = '.';
		}
		for(int j = split+1;j <= m;j++){
			mp[i][j] = '#';
		}
	}
	for(int i = 1;i <= n && b;i += 2){
		for(int j = 1;j < split && b;j += 2){
			--b;
			mp[i][j] = '#';
		}
	}
	for(int i = 1;i <= n && a;i += 2){
		for(int j = split+2;j <= m && a;j += 2){
			--a;
			mp[i][j] = '.';
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	return 0;
}
