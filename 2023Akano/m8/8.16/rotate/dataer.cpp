#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
using pii = pair<int,int>;
bool CASE1 = false;
bool CASE2 = false;
bool CASE3 = false;
bool CASE4 = false;
namespace Make{
	Rander rd;
	pii ST = {200,300};
	pii NM = {5000,6000};
	const int MAXVAL = 4e6;
	const int MAXST = 606;
	string str1[MAXST],str2[MAXST];
	inline string Cut(const string& str,int l,int r){
		string ret;
		for(int i = l;i <= r;i++){
			ret += str[i];
		}
		return ret;
	}
	inline void Make(){
		if(CASE3){
			ST = {4,6};
			NM = {5,10};
		}
		if(CASE4){
			ST = {100,200};
			NM = {1000,2000};
		}
		int poss = rd(40,60);
		int s = rd(ST.first,ST.second),t = rd(ST.first,ST.second);
		int n = rd(NM.first,NM.second),m = rd(NM.first,NM.second);
		while((n + m) % 2 == 1 || s * n + t * m >= MAXVAL){
			s = rd(ST.first,ST.second),t = rd(ST.first,ST.second);
			n = rd(NM.first,NM.second),m = rd(NM.first,NM.second);
		}
		if(CASE1){
			if(n < m)swap(n,m);
		}
		if(CASE2){
			int mn = min(n,m);
			n = mn,m = mn;
		}
		int len = n + m,st = min(s,t);
		for(int i = 1;i <= st;i++){
			if(rd(1,100) <= poss){//poss概率可以配对 
				string tot = "." + RandString(len/2);
				int it1 = rd(1,len/2);
				string ans = "." + Cut(tot,it1,len/2) + Cut(tot,1,it1-1);
				ans += Cut(tot,1,len/2);
				str1[i] = Cut(ans,1,n),str2[i] = Cut(ans,n+1,len);
			}else{
				str1[i] = RandString(n),str2[i] = RandString(m);
			}
		}
		for(int i = st+1;i <= s;i++){
			if(rd(1,100) <= 80){//选择之前的,更大概率可以匹配 
				str1[i] = str1[rd(1,st)];
			}else{
				str1[i] = RandString(n);
			}
		}
		for(int i = st+1;i <= t;i++){
			if(rd(1,100) <= 80){//选择之前的,更大概率可以匹配 
				str2[i] = str2[rd(1,st)];
			}else{
				str2[i] = RandString(m);
			}
		}
		cout<<s<<" "<<t<<" "<<n<<" "<<m<<endl;
		for(int i = 1;i <= s;i++){
			cout<<str1[i]<<endl;
		}
		for(int i = 1;i <= t;i++){
			cout<<str2[i]<<endl;
		}
		return ;
	}
}
namespace Solve{
	using std::cin;
	using std::cout;
	using LL = long long;
	using ull = unsigned long long;
	using ld = long double;
	const int maxn = 10010;
	
	int n,m,slen,tlen,mid;
	std::string S[maxn],T[maxn];
	
	std::unordered_map<std::string,int> buck;
	char fix[maxn];
	inline void Clear(){
		buck.clear();
		memset(fix,0,sizeof(fix));
		return ;
	}
	void solve1() {
		int fixlen = slen-mid;
		for(int i=1; i<=n; i++) {
			std::string s = S[i];
			std::string cut = s.substr(0,mid) + s.substr(0,mid);
			for(int j=mid; j<slen; j++) fix[j%mid]=s[j];
	
			// 枚举起始点--匹配
			for(int j=0; j<mid; j++) {
				bool AC=1;
				for(int k=0; k<fixlen; k++) {
					if(cut[j+k]!=fix[k]) {
						AC=0;
						break;
					}
				}
				if(AC) { // 匹配上
					buck[cut.substr(j+fixlen,tlen)]++;
				}
			}
		}
		int ans=0;
		for(int i=1; i<=m; i++) {
			ans+=buck[T[i]];
		}
		cout << ans;
	}
	
	void solve2() {
		// md u->v == v->u
		int fixlen = tlen-mid;
		for(int i=1; i<=m; i++) {
			std::string t = T[i];
			std::string cut = t.substr(fixlen) + t.substr(fixlen);
			for(int j=0; j<fixlen; j++) fix[j]=t[j];
			// 枚举起始点--匹配后缀
			for(int j=0; j<mid; j++) {
				bool AC=1;
				int jj=j+mid-fixlen;
				for(int k=0; k<fixlen; k++) {
					if(cut[jj+k]!=fix[k]) {
						AC=0;
						break;
					}
				}
	//			cout << AC << '\n';
				// ---
				if(AC) { // 匹配上了后缀。。。
					buck[cut.substr(j,slen)]++;
				}
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			ans+=buck[S[i]];
		}
		cout << ans;
	}
	
	inline void Solve() {
		Clear();
		cin >> n >> m >> slen >> tlen;
		mid = slen+tlen>>1;
		for(int i=1; i<=n; i++) cin >> S[i];
		for(int i=1; i<=m; i++) cin >> T[i];
		if(slen >= tlen) solve1();
		else solve2();
	
		return ;
	}

}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("rotate",1,25,Make::Make,Solve::Solve);
	return 0;
}
