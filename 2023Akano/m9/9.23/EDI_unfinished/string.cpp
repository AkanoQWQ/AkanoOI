#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const int MAXN = 2e5 + 1018 + 1108;
const int base = 33;
int n,q;
ull hashL[MAXN],hashR[MAXN],basep[MAXN];
string str;
inline void ReadIn(){
	cin>>n>>q;
	cin>>str;
	str = "." + str;
	return ;
}
inline void GetHash(){
	basep[0] = 1;
	for(int i = 1;i <= n;i++)basep[i] = basep[i-1] * base;
	for(int i = 1;i <= n;i++){
		hashL[i] = hashL[i-1] * base + str[i] - 'a';
	}
	for(int i = n;i >= 1;i--){
		hashR[i] = hashR[i+1] * base + str[i] - 'a';
	}
	return ;
}
inline ull CutL(int l,int r){
	return hashL[r] - hashL[l-1] * basep[r - l + 1];
}
inline ull CutR(int l,int r){
	return hashR[l] - hashR[r+1] * basep[r - l + 1];
}
inline bool EST(int l,int r){
	const int mid = (l + r) >> 1;
	if(mid*2 == l+r){
		return CutL(l,mid) == CutR(mid,r);
	}else{
		return CutL(l,mid) == CutR(mid+1,r);
	}
}
inline void Solve(){
	for(int i = 1;i <= q;i++){
		int l,r,ans = 0;
		cin>>l>>r;
		for(int i = l;i < r;i++){
			if(EST(l,i) && EST(i+1,r))ans++;
		}
		cout<<ans<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ReadIn();
	GetHash();
	Solve();
	return not(Akano loves pure__Elysia);
}
