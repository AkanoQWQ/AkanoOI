#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

unordered_map<string,bool> cnt;
int n,ans;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>str;
		if(!cnt[str]){
			ans++;
			cnt[str] = true;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

