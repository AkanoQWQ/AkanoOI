#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 6;
int n,k,arr[MAXN],ans;
vector<int> vec;
bool Cmp(int a,int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		if(i != 1)vec.push_back(arr[i] - arr[i-1] - 1);
	}
	ans = arr[n] - arr[1] + 1;
	sort(vec.begin(),vec.end(),Cmp);
	k--;
	for(auto i : vec){
		if(k <= 0 || i <= 0)break;
		k--;
		ans -= i;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
