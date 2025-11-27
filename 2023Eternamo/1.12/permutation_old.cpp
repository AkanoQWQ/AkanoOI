#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,d,a[11],ow[11];
string s;
ll wei[11] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
inline ll iread(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline string sread(){
	string ret = "";
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret += ch;
		ch = getchar();
	}
	return ret;
}
int main(){
	freopen("permutation.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s>>d;
		const int len = s.length(),mod = d;
		int cnt = 0;
		for(int i = 0;i <= 10;i++)ow[i] = 0;
		for(int i = 1;i <= len;i++){
			a[i] = i;
			ow[s[i-1]-'0']++;
		}
		do{
			ll num = 0;
			for(int i = 0;i < len;i++){
				num += wei[i] * (s[a[i+1]-1] - '0');
			}
			cnt += ((num % mod) == 0);
		}while(next_permutation(a+1,a+len+1));
		for(int i = 0;i <= 10;i++){
			if(ow[i] > 1)cnt /= (1<<(ow[i]-1));
		}
		cout<<cnt<<endl;
	}
	return 0;
}
