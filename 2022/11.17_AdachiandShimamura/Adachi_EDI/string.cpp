#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int t,ans;
string s,ss;
string getstr(int a,int b){
	string ret = "";
	for(int i = a;i <= b;i++){
		ret += s[i];
	}
	return ret;
}
int tong[26];
int count(const string& str){
	memset(tong,0,sizeof(tong));
	for(int i = 0;i < str.length();i++){
		tong[str[i] - 'a']++;
	}
	int ret = 0;
	for(int i = 0;i < 26;i++){
		ret += tong[i] & 1;
	}
	return ret;
}
void calc(int a,int b){
	string sa = getstr(1,a);
	string sb = getstr(a+1,a+b);
	string ab = sa + sb;
	string res = getstr(a+b+1,s.length()-1);
//	cout<<s<<" in "<<a<<","<<b<<" "<<sa<<","<<sb<<" res "<<res<<endl;
	for(int i = 0;(a+b)*(i+1)+1 <= s.length()-1;i++){
		bool able = 1;
		for(int j = 1;j <= i;j++){
			string more = getstr(j*(a+b)+1,(j+1)*(a+b));
//			cout<<"more "<<more<<endl;
			if(more != ab){
				able = 0; 
				break;
			}
		}
		string realres = getstr((a+b)*(i+1)+1,s.length()-1);
		if(count(sa) > count(realres))able = 0;
		ans += able;
	}
	return ;
}
EXCUTE_ST
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s;
		s = "." + s;
		ans = 0;
		const int n = s.length()-1;
		for(int r1 = 1;r1 <= n;r1++){
			for(int r2 = 1;r1+r2+1 <= n;r2++){
				calc(r1,r2);
			}
		}
		cout<<ans<<endl; 
	}
FILE_ED_And_excute
