#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a % b);
}
int n;
vl arr,ans,save;
inline bool Judge(ll nowval){
	if(arr.empty())return true;
	save = arr;
	int idx = arr.size();
	for(int i = 0;i < idx;i++){
		for(int j = 0;j < i;j++){
			arr[i] /= gcd(arr[i],arr[j]);
		}
	}
	for(auto i : arr){
		nowval /= gcd(nowval,i);
	}
	arr = save;
	return (nowval != 1);
}
inline void Solve(){
	while(!arr.empty()){
		int sz = arr.size();
		bool OK = false;
		for(int i = 0;i < sz;i++){
			ll nowval = arr[0];
			arr.erase(arr.begin());
			if(Judge(nowval)){
				OK = true;
				ans.push_back(nowval);
				break;
			}else{
				arr.push_back(nowval);
			}
		}
		if(!OK)break;
	}
	return ;
}
inline void Output(){
	if(!arr.empty()){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
	reverse(ans.begin(),ans.end());
	for(auto i : ans){
		cout<<i<<" ";
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	arr.reserve(n),ans.reserve(n);
	for(int i = 1;i <= n;i++){
		ll inx;
		cin>>inx;
		arr.push_back(inx);
	}
	Solve();
	Output();
	return 0;
}
