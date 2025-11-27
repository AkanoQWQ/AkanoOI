#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 3e5 + 1018 + 1108;
int n,arr[MAXN],f[MAXN];
string str;
set<pair<int,int> > up,down;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	cin>>str;
	str = "." + str;
	for(int i = 1;i <= n;i++){
		auto it1 = up.lower_bound(make_pair(arr[i],0));
		if(it1 != up.begin()){
			it1--;
			f[i] = max(f[i],(*it1).second);
		}
		auto it2 = down.upper_bound(make_pair(arr[i],0));//upper,lower应该一样的
		if(it2 != up.end()){
			f[i] = max(f[i],(*it2).second);
		}
		if(str[f[i]+1] == 'U'){
			auto it = up.insert(make_pair(arr[i],f[i]+1)).first;
			while(true){
				auto nxt = it;
				nxt++;
				if(nxt == up.end())break;
				if((*nxt).second <= f[i] + 1){
					up.erase(nxt);
				}else{
					break;
				}
			}
		}else{
			auto it = down.insert(make_pair(arr[i],f[i]+1)).first;
			while(it != down.begin()){
				auto pre = it;
				pre--;
				if((*pre).second <= f[i] + 1){
					down.erase(pre);
				}else{
					break;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans,f[i]);
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
