#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
vector<int> vec;
int n,a[MAXN],b[MAXN];
int c[MAXN];
inline void CountingSort(int mx){
	for(int i = 1;i <= mx;i++){
		c[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		c[a[i]]++;
	}
	for(int i = 1;i <= mx;i++){
		c[i] += c[i-1];
	}
	for(int i = n;i >= 1;i--){
		b[c[a[i]]--] = a[i];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
	}
	CountingSort(vec.size());
	for(int i = 1;i <= n;i++){
		a[i] = vec[b[i]-1];
		cout<<a[i]<<" ";
	}
	return 0;
}
