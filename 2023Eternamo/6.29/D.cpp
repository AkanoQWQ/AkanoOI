#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 4; 
const long long INF = 1e18;
int T,n;
long long a[MAXN],s[MAXN],mn[MAXN],ans,k;
int main(){
	//freopen("D.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			s[i] = s[i-1] + a[i];
		}
		mn[n+1] = s[n] + 1;
		for(int i = n;i >= 1;i--){
			mn[i] = min(mn[i+1],s[i]);
		}
		mn[0] = min(mn[1],0ll);
		ans = -mn[0];k = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] - mn[i] > ans){
				ans = s[i] - mn[i];
				k = s[i];
			}
		}
		cout<<k<<endl;
	}
	return 0;
}

