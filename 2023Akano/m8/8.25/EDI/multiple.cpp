#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 5e5 + 1018 + 1108;
int n,arr[MAXN],l[MAXN][22],r[MAXN][22],ans;
const int up = 20;
vector<int> vec;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	arr[n+1] = arr[n],arr[0] = arr[1];
	for(int i = n;i >= 1;i--){
		r[i][0] = __gcd(arr[i],arr[i+1]);
		for(int j = 1;j <= up;j++){
			int got = min(n,i + (1<<(j-1)));
			r[i][j] = __gcd(r[i][j-1],r[got][j-1]);
		}
	}
	for(int i = 1;i <= n;i++){
		l[i][0] = __gcd(arr[i],arr[i-1]);
		for(int j = 1;j <= up;j++){
			int got = max(1,i - (1<<(j-1)));
			l[i][j] = __gcd(l[i][j-1],l[got][j-1]);
		}
	}
	for(int i = 1;i <= n;i++){
		int nowl = i,nowr = i;
		for(int j = up;j >= 0;j--){
			if(nowl - (1<<j) >= 1 && l[nowl][j] % arr[i] == 0){
				nowl -= 1<<j;
			}
			if(nowr + (1<<j) <= n && r[nowr][j] % arr[i] == 0){
				nowr += 1<<j;
			}
		}
		if(nowr - nowl > ans){
			ans = nowr - nowl;
			vec.clear();
			vec.push_back(nowl);
		}else if(nowr - nowl == ans){
			vec.push_back(nowl);
		} 
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	cout<<vec.size()<<" "<<ans<<'\n';
	for(auto i : vec)cout<<i<<" ";
	return 0;
}
