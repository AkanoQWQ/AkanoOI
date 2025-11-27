#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int t,n,m,a[MAXN],b[MAXN],cnt[35],mx[35],mn[35];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		int mnans = 0,mxans = 0;
		for(int i = 0;i <= 33;i++)cnt[i] = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			mnans ^= a[i],mxans ^= a[i];
			for(int j = 0;j < 32;j++){
				if((1ll<<j) & a[i])cnt[j]++;
			}
		}
		for(int i = 0;i < 32;i++)mn[i] = mx[i] = cnt[i];
		for(int i = 1;i <= m;i++){
			cin>>b[i];
			int mxdelta = 0,mndelta = 0;
			for(int j = 0;j < 32;j++){
				if(not((1ll<<j) & b[i]))continue;
				mxdelta += (1<<j) * (n & 1) - (1<<j) * (mx[j] & 1);
				mndelta += (1<<j) * (n & 1) - (1<<j) * (mn[j] & 1);
			}
			if(mxdelta > 0){
				mxans += mxdelta;
				for(int j = 0;j < 32;j++){
					if(not((1ll<<j) & b[i]))continue;
					mx[j] = n;
				}
			}
			if(mndelta < 0){
				mnans += mndelta;
				for(int j = 0;j < 32;j++){
					if(not((1ll<<j) & b[i]))continue;
					mn[j] = n;
				}
			}
		}
		cout<<mnans<<" "<<mxans<<endl;
	}
	return 0;
}

