#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 1018 + 1108;
int sa[MAXN],rk[MAXN],old[MAXN],noww;
bool cmp(int a,int b){
	if(rk[a] != rk[b])return rk[a] < rk[b];
	return rk[a+noww] < rk[b+noww];
}
inline void GetSA(const string& str){
	int n = str.length() - 1;
	for(int i = 1;i <= n;i++){
		sa[i] = i;
		rk[i] = int(str[i]);
	}
	for(int w = 1;w < n;w *= 2){
		int cnt = 0;
		noww = w;
		sort(sa+1,sa+n+1,cmp);
		swap(rk,old);
		for(int i = 1;i <= n;i++){
			if(old[sa[i]] == old[sa[i-1]] && old[sa[i]+w] == old[sa[i-1]+w]){
				rk[sa[i]] = cnt;
			}else{
				rk[sa[i]] = ++cnt;
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	
	return 0;
}
