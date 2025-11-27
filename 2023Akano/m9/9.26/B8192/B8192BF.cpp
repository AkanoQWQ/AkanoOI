#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
string main_str;
int n;
ll ans;
inline string Cut(const string& str,int l,int r){
	string ret;
	for(int i = l;i <= r;i++)ret += str[i];
	return ret;
}
ll Solve(string str,int st){
	ll ret = 0;
	int len = str.length();
	str = "." + str;
	for(int len1 = 1;len1 <= n;len1++){
		for(int len2 = 1;len2 <= n;len2++){
			int a = 1,b = a + len1,c = b + len1,d = c + len2;
			int f = len + 1 - len2,e = f - len1;
			if(d >= e)continue;
			string stra = Cut(str,a,a+len1-1),strb = Cut(str,b,b+len1-1);
			string strc = Cut(str,c,c+len2-1),strd = Cut(str,d,e-1);
			string stre = Cut(str,e,e+len1-1),strf = Cut(str,f,f+len2-1);
			if(stra == strb && strb == stre && strc == strf){
				cerr<<st+b-1<<" to "<<st+d-1-1<<" get "<<st<<" to "<<st+len-1<<endl;
				ret++;
			}
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>main_str;
	n = main_str.length();
	main_str = "." + main_str;
	for(int i = 1;i <= n;i++){
		string now = "";
		for(int j = i;j <= n;j++){
			now += main_str[j];
			ans += Solve(now,i);
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
