#include<bits/stdc++.h>
using namespace std;
//Ф־� 
const int maxn = 100060;
int a[maxn],n,q,i,j,k;
int f[maxn][30];

void bf(){
	int i = 0;
	for(int i = 1;i <= n;i++){
		f[i][0] = a[i];
	}
	i = 1; 
	for(int i = 1;(1<<i) <= n;i++){
		for(int j = 1;(1<<i)-1 <= n;j++){
			f[j][i] = max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
}






int query(int l,int r){
	int k = 0;
	while((1<<(k+1)) <= r-l+1){
		k++;
	}
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	freopen("st.in","r",stdin);
	//freopen("st.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i+1]);
	}
	
	bf();
	
	for(i = 1;i <= q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
