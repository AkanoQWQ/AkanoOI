#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int no,t,n,q;
string str;
namespace Subtask1{
	inline string Cut(int l,int r){
		string ret = "";
		for(int i = l;i <= r;i++){
			ret += str[i];
		}
		return ret;
	}
	inline void Solve(){
		cin>>n>>q>>str;
		str = "." + str;
		while(q--){
			int st,r,ans = 0;
			cin>>st>>r;
			for(int l = 1;l <= r;l++){
				string s1 = Cut(st,st+l-1),s2 = Cut(st+l,st+l+l-1);
				reverse(s2.begin(),s2.end());
				ans += (s1 < s2);
			}
			cout<<ans<<'\n';
		}
		return ;
	}
}
namespace Subtask2{
	const int MAXN = 1e5 + 2006 + 1018 + 1108;//TEST!
	const int bs = 29;
	ull stp[MAXN];
	ull L[MAXN],R[MAXN];
	inline ull CutL(int l,int r){
		ull ret;
		ret = L[r] - L[l-1] * stp[r-l+1];
		return ret;
	}
	inline ull CutR(int l,int r){
		ull ret;
		ret = R[l] - R[r+1] * stp[r-l+1];
		return ret;
	}
	inline void Pre(){
		stp[0] = 1;
		for(int j = 1;j <= n;j++){
			stp[j] = stp[j-1] * bs;
		}
		for(int i = 1;i <= n;i++){
			L[i] = L[i-1] * bs + str[i] - 'a';
		}
		for(int i = n;i >= 1;i--){
			R[i] = R[i+1] * bs + str[i] - 'a';
		}
		return ;
	}
	inline bool Judge(int st,int len){//st   st+l+l-1
		const int ed = st + len + len - 1;
		int l = 1,r = len+1;
		while(l < r){
			const int mid = (l + r) >> 1;
			if(CutL(st,st+mid-1) == CutR(ed-mid+1,ed)){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		const int finlen = l - 1;
		if(finlen == len)return false;
		return str[st + finlen] < str[ed - finlen];
	}
	inline void Solve(){
		cin>>n>>q>>str;
		str = "." + str;
		Pre();
		while(q--){
			int st,r,ans = 0;
			cin>>st>>r;
			for(int l = 1;l <= r;l++){
				ans += Judge(st,l);
			}
			cout<<ans<<'\n';
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>no>>t;
	while(t--){
		Subtask2::Solve();
		continue;
		if(no <= 5){//Point 1~5
			Subtask1::Solve();
		}else if(no <= 9){//Point6~9
			Subtask2::Solve();
		}
	}
	return 0;
}
