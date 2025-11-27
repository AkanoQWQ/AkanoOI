#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 6;
int n,a[MAXN],b[MAXN];
ll ans;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void merge_sort(int l,int r){
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i = l,j = mid + 1,t = l;
	while(i <= mid && j <= r){
		if(a[i] > a[j]){
			ans += mid - i + 1;
			b[t++] = a[j++]; 
		}else{
			b[t++] = a[i++];
		}
	}
	while(i <= mid){
		b[t++] = a[i++];
	}
	while(j <= r){
		b[t++] = a[j++];
	}
	for(int i = l;i <= r;i++){
		a[i] = b[i];
	}
	return ;
}
int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	merge_sort(1,n);
	printf("%lld",ans);
	return 0;
}

