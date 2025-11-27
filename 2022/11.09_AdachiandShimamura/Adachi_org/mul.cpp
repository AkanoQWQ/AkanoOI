#include<bits/stdc++.h>
using namespace std;
int n,a[106],b[106],ans = 0;
bool benif[106],opt[106];
int main(){
	freopen("mul.in","r",stdin);
	freopen("mul.out","w",stdout);
	srand(20061108);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		int oj = 0;
		for(int j = i;j <= n;j += i){
			oj += a[j];
		}
		benif[i] = (oj > 0);
	}
	while(clock() < 1920){
		for(int i = 1;i <= n;i++){
			b[i] = a[i];
			opt[i] = 0;
		}
		int rdn = rand()%(n-1) + 2;
		for(int i = 1;i <= rdn;i++){
			int r2 = rand()%(n-1) + 2;
			if(opt[r2])continue;
			if(benif[r2]){
				if(rand()%25 != 0)continue;
			}
			for(int j = r2;j <= n;j += r2){
				b[j] = 0;
			}
			opt[r2] = 1;
		}
		int s = 0;
		for(int i = 1;i <= n;i++){
			s += b[i];
		}
		ans = max(ans,s);
	}
	cout<<ans;
	return 0;
}

