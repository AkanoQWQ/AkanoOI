#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll x,mx,bs,md;
vector<int> ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>x>>mx>>bs>>md;
	ll obj = 1;
	while(x--)obj = (obj * bs) % md;
	ll now = 1;
	for(int i = 0;i <= mx;i++){
		if(now == obj)ans.push_back(i);
		now = (now * bs) % md;
	}
	cout<<ans.size()<<endl;
	for(auto i : ans){
		cout<<i<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
