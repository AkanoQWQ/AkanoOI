#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int n,c;
long long ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>c;
		mp[c]++;
	}
	for(auto i : mp){
		if(i.second < i.first){
			ans += i.second;
		}else{
			ans += i.second - i.first;
		}
	}
	cout<<ans;
	return 0;
}

