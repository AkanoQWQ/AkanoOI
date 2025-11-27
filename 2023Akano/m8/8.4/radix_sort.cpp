#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 4;
int n;
string str[MAXN],tmp[MAXN];
int c[31];
inline void CountingSort(int k){
	for(int i = 0;i <= 26;i++)c[i] = 0;
	for(int i = 1;i <= n;i++){
		c[str[i][k] - 'a' + 1]++;
	}
	for(int i = 1;i <= 26;i++){
		c[i] += c[i-1];
	}
	for(int i = n;i >= 1;i--){
		tmp[c[str[i][k] - 'a' + 1]--] = str[i];
	}
	for(int i = 1;i <= n;i++){
		str[i] = tmp[i];
	}
	return ;
}
inline void RadixSort(){
	int len = 0;
	for(int i = 1;i <= n;i++){
		len = max(len,int(str[i].length()));
	}
	for(int i = 1;i <= n;i++){
		while(str[i].length() < len)str[i] += char('a' - 1);
	}
	for(int i = len-1;i >= 0;i--){
		CountingSort(i);
	}
	return ;
}
inline void Solve(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>str[i];
	}
	RadixSort();
	for(int i = 1;i <= n;i++){
		cout<<str[i]<<endl;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Solve();
	return 0;
}
