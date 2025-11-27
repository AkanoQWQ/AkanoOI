#include<bits/stdc++.h>
using namespace std;
const int MAXP = 15000006;
const int MAXN = 300006;
bitset<MAXP> est;
int prime[MAXP],pnt;
void ES(int n){
	for(int i = 1;i <= n;i++)est[i] = 1;
	est[1] = 0;
	for(int i = 2;i <= n;i++){
		if(est[i]){
			prime[++pnt] = i;
			for(int j = 2;j*i <= n;j++){
				est[j*i] = 0;
			}
		}
	}
	return ;
}
int n,a[MAXN],cntmaxa,z[MAXP],mn[MAXP],ans = 0x7fffffff;
int bgn[MAXP],lstz[MAXP];
int main(){
	freopen("gcd.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		cntmaxa = max(cntmaxa,a[i]);
	}
	//ES(int(sqrt(cntmaxa)));
	ES(cntmaxa);
	cout<<int(sqrt(cntmaxa))<<endl;
	for(int i = 1;i <= pnt;i++){
		z[i] = 0x7fffffff;
	}
	for(int i = 1;i <= n;i++){
		int s = a[i];
		for(int j = 1;j <= pnt;j++){
			int prn = 0;
			while(s%prime[j] == 0){
				prn++;
				s /= prime[j];
			}
			if(prn < z[j]){
				if(z[j] != 0x7fffffff){
					bgn[j] = 1;
				}
				mn[j] = 1;
				z[j] = prn;
			}else if(prn == z[j]){
				mn[j]++;
			}else{
				bgn[j] = 1;
			}
			//if(s <= 1)break;
		}//149971 4
	}
	for(int i = 1;i <= pnt;i++){
		if(mn[i] == n || z[i] == 0x7fffffff || bgn[i] == 0)continue;
		ans = min(ans,mn[i]);
	}
	if(ans == 0x7fffffff){
		cout<<-1;
	}else{
		cout<<ans;
	}
	return 0;
}

