#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXW = 14;
int a[MAXN],b[MAXN],c[MAXW],n;
inline void CountingSort(int w){
	for(int i = 0;i <= 9;i++){
		c[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		c[(a[i] / w) % 10]++;
	}
	for(int i = 1;i <= 9;i++){
		c[i] += c[i-1];	
	}
	for(int i = n;i >= 1;i--){
		b[c[(a[i] / w) % 10]--] = a[i];
	}
	for(int i = 1;i <= n;i++){
		a[i] = b[i];
	}
	return ;
}
inline void RadixSort(){
	int mx = 0;
	for(int i = 1;i <= n;i++){
		mx = max(mx,a[i]);
	}
	long long k = 1;
	while(k <= mx){
		CountingSort(k);
		k *= 10;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	RadixSort();
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
