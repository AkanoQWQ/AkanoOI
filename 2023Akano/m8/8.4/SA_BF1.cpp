#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 1018 + 1108;
int sa[MAXN],rk[MAXN],old[MAXN],noww,n;
bool cmp(int a,int b){
	if(rk[a] != rk[b])return rk[a] < rk[b];
	return rk[a+noww] < rk[b+noww];
}
string str;


int c[MAXN];
inline void CountingSort(int w){
	for(int i = 0;i <= n;i++){
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
inline void GetSA(){
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
	cin>>str;
	n = str.length();
	str = "." + str;
	GetSA();
	for(int i = 1;i <= n;i++){
		cout<<sa[i]<<" ";
	}
	cout<<endl;
	return 0;
}

