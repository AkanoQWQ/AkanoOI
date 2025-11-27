#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
int T,a[MAXN],n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		int ands = (1<<30)-1;
		int ans = 1;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			ands &= a[i];
			if(ands == 0){
				++ans;
				ands = (1<<30)-1;
			}
		}
		if(ands != 0)--ans;
		if(ans <= 0)ans = 1;
		cout<<ans<<endl;
	}
	return 0;
}

