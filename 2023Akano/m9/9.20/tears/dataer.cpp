#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXVAL = 300;
const int MAXN = 5e5 + 1018 + 1108;
Rander rd;
inline void Make(){
	int n = 1e5,m = 2.5e5;
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(0,MAXVAL)<<" ";
	}
	cout<<endl;
	for(int i = 1;i <= m;i++){
		int l = rd(1,n),r = rd(1,n);
		if(l > r)swap(l,r);
		cout<<l<<" "<<r<<endl;
	}
	return ;
}
int cnt[MAXN + 2],arr[MAXN];
inline void Solve(){
	return ;
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int q = 1;q <= m;q++){
		int l,r;
		cin>>l>>r;
		memset(cnt,0,sizeof(cnt));
		for(int i = l;i <= r;i++)cnt[arr[i]]++;
		for(int i = 1;i <= n;i++)cnt[i] += cnt[i-1];
		int ans = 0;
		for(int i = 0;i <= n;i++){
			if(cnt[i] >= i+1)ans = i+1;
		}
		cout<<ans<<endl;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("tears",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}

