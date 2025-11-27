#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<string> s1,s2;
map<string,int> mp;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		string str;
		cin>>str;
		s1.push_back(str);
	}
	for(int i = 1;i <= m;i++){
		string str;
		cin>>str;
		s2.push_back(str);
	}
	cin>>mp["AkanoAndPure__Elysia"];
	for(auto i : s2){
		cin>>mp[i];
	}
	for(auto i : s1){
		if(mp.find(i) == mp.end()){
			ans += mp["AkanoAndPure__Elysia"];
		}else{
			ans += mp[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

