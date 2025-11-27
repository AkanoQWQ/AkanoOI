#include<bits/stdc++.h>
using namespace std;
const int maxn = 206;
int n,m,a[maxn],b[maxn],c[maxn],d[maxn],e[maxn],f[maxn],i,j,k,lq[maxn],ans,mans;
int s(int x){
	int i;
		for(i = 1;i <= k;i++){
			if(!e[i]){
			e[i] = 1;
			f[x] = i%2;
			if(x == k){
				ans = 0;
				/*for(j = 1;j <= k;j++){
					cout<<f[j]<<" ";
				}
				cout<<endl;
				*/
				for(i = 0;i < k;i++){
					if(f[i] == 1){
						lq[c[i]] = 1;
					}else{
						lq[d[i]] = 1;
					}
				}
				for(i = 0;i < n;i++){
					if(lq[a[i]] == 1 &&lq[b[i]] == 1){
						ans++;
					}
				}
				if(ans > mans){
					mans = ans;
				}
			}else{
				s(x+1);
			}
			e[i] = 0;
		}
	}
}
int main(){
	freopen("study.in","r",stdin);
	freopen("study.out","w",stdout);
	cin>>n>>m;
	for(i = 0;i < m;i++){
		cin>>a[i]>>b[i];
	}
	cin>>k;
	for(i = 0;i < k;i++){
		cin>>c[i]>>d[i];
	}
	s(1);
	cout<<mans;
	return 0;
}

