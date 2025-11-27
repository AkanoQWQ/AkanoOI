#include<bits/stdc++.h>
using namespace std;
int n = 100000,ans,pls;
bool vis[2000000];
int main(){
	srand(114514);
	//freopen(".in","r",stdin);
	freopen("B.in","w",stdout);
	while(ans < 2000000){
		int pre = ans;
		ans += 1;
		vis[ans] = 1;
		//cout<<ans<<endl;
		ans += pls;
		vis[ans] = 1;
		//cout<<ans<<endl;
		ans += pls;
		vis[ans] = 1;
		//cout<<ans<<endl;
		pls++;
	}
	cout<<n<<endl;
	while(n--){
		int l,r;
		int r2 = rand()%2;
		if(rand()%2 == 0)r2 = -r2;
		int l2 = rand()%2;
		if(rand()%2 == 0)l2 = -l2;
		l = rand()%1000000;
		while(!vis[l])l = rand()%1000000;
		r = l + rand()%100000;
		while(!vis[r])r = l + rand()%100000;
		cout<<l+l2+2<<" "<<r+r2+2<<endl;
	}
	return 0;
}

