#include<bits/stdc++.h>
using namespace std;
const int MAXDEP = 10000;
int n,m,ans,xn,inq;
const int MOD = 998244353;
string inm;
int GetModM(){
	long long ret = 0;
	int a = 1;
	for(int i = 0;i < n;i++){
		int pos = n-i-1;
		ret += (inm[pos]-'0') * a;
		ret %= MOD;
		a = (a*2) % MOD;
	}
	return int(ret);
}
int main(){
	freopen("fdu.in","r",stdin);
	freopen("fdu.out","w",stdout);
	cin>>n>>inm;
	if(n >= 30){
		cout<<"Never gonna give you up"<<endl;
		return 0;
	}
	for(int i = 0;i < n;i++){
		int pos = n-i-1;
		m += (inm[pos]-'0') << i;
	}
	xn = 1 << (n-1);
	for(int x = 0;x <= m;x++){
		int pos = x;
		ans = 1;
		if(pos % 2 == 0){
			pos = (x/2) + xn;
		}else{
			pos = (pos-1) / 2;
		}
		while(pos != x && ans < MAXDEP){
			ans++;
			if(pos % 2 == 0){
				pos = (pos/2) + xn;
			}else{
				pos = (pos-1) / 2;
			}
		}
		if(ans < MAXDEP){
			inq += ans;
			while(inq >= MOD)inq -= MOD;
		}
	}
	inq %= MOD;
	cout<<inq<<endl;
	return 0;
}
