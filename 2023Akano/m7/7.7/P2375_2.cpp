#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
const int MAXN = 1e6 + 6;
const int MOD = 1e9 + 7;
int pi[MAXN],fail[MAXN],ans[MAXN];
inline void KMP(const string& str){
	const int len = str.length();
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(j && str[i] != str[j])j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
		fail[i] = pi[i-1],ans[i] = ans[fail[i]]+1;
	}
	return ;
}
int n,num,len;
string s;
int main(){
	//freopen("P2375_2.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		int otp = 1;
		cin>>s;
		KMP(s);
		len = s.length();
		int j = 0;
		for(int i = 1;i < len;i++){
			while(j && s[i] != s[j])j = fail[j];
			if(s[i] == s[j])++j;
			while(2*j > i+1)j = fail[j];
			num = ans[j];
			otp = (1ll * otp * (num+1)) % MOD;
		}
		cout<<otp<<endl;
	}
	return 0;
}
