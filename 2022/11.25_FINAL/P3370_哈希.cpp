#include<bits/stdc++.h>
using namespace std;
const int MOD1 = 10000009;
const int p1 = 63;
const int MOD2 = 19260817;
const int p2 = 67;
int n,ans;
string s;
bitset<MOD2 + 5> vis[2];
int to(const char& c){
	if(c >= '0' && c <= '9')return c - '0';
	if(c >= 'a' && c <= 'z')return c - 'a' + 10;
	if(c >= 'A' && c <= 'Z')return c - 'A' + 36;
	return 0;
}
int HS(const string& str,int md,int p){
	int len = str.length() - 1,ret = 0;
	for(int i = 0;i <= len;i++){
		ret = (1ll * ret * p + to(str[i])) % md;
	}
	return ret;
}
int main(){
	cin>>n;
	while(n--){
		cin>>s;
		int hash1 = HS(s,MOD1,p1);
		int hash2 = HS(s,MOD2,p2);
		if(vis[0][hash1] == 0 && vis[1][hash2] == 0){
			vis[0][hash1] = vis[1][hash2] = 1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
