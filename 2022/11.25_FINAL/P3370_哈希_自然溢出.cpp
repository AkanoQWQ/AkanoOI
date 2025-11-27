#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int MAXN = 10006;
int n,ans;
string s;
ull a[MAXN];
int to(const char& c){
	if(c >= '0' && c <= '9')return c - '0';
	if(c >= 'a' && c <= 'z')return c - 'a' + 10;
	if(c >= 'A' && c <= 'Z')return c - 'A' + 36;
	return 0;
}
ull HS(const string& str,int p){
	int len = str.length() - 1;
	ull ret = 0;
	for(int i = 0;i <= len;i++){
		ret = ret * p + to(str[i]);
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s;
		ull hash1 = HS(s,131);
		a[i] = hash1;
	}
	sort(a+1,a+n+1);
	ans = unique(a+1,a+n+1) - a - 1;
	cout<<ans;
	return 0;
}
