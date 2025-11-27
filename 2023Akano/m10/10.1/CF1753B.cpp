#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
inline bool ISP(int x){
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0)return false;
	}
	return true;
}
vector<int> pr;
int a[MAXN],n,x,cnt[MAXN],val[MAXN],no[MAXN],query[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>x;
	for(int i = 2;i <= x;i++){
		if(ISP(i)){
			pr.push_back(i);
			no[i] = int(pr.size()) - 1;
		}
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i = x;i >= 1;i--){
		cnt[i] += cnt[i+1];
		cerr<<i<<" cnt "<<cnt[i]<<endl;
		int num = i;
		for(int j = 2;j*j <= i;j++){
			int app = 0;
			while(num % j == 0){
				num /= j;
				app++;
			}
			val[no[j]] += app * cnt[i];
			query[no[j]] += app;
		}
		if(num != 1){
			val[no[num]] += cnt[i];
			query[no[num]] += 1;
		}
	}
	for(int i = 0;i < int(pr.size());i++){
		if(val[i] < query[i]){
			cout<<"No"<<endl;
			cerr<<"wa in "<<pr[i]<<" have "<<val[i]<<" need "<<query[i]<<endl;
			return not(Akano loves pure__Elysia);
		}
	}
	cout<<"Yes"<<endl;
	return not(Akano loves pure__Elysia);
}
