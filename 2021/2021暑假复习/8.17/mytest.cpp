#include<bits/stdc++.h>
using namespace std;
long long h,w,d,i,j,k,c,q,l,ans,r[4100][4100],hw,rr,aaa;
struct pos{
	long long x,y;
}a[90006];
int main(){
	freopen("test2.in","r",stdin);
	freopen("test2.out","w",stdout);
	cin>>h>>w>>d;
	hw = h * w;
	for(i = 1;i <= h;i++){
		for(j = 1;j <= w;j++){
			a[i].x = i,a[j].y = j;
		}
	}
	
	for(i = 1;i <= hw;i++){
		for(j = i+1;j <= hw;j++){
			r[i][j] = 1;
			r[j][i] = 2;
		}
	}
	cout<<"test";
	q = 100000;
	while(q--){
		ans = 0;
		aaa = 300;
		while(aaa--){
			ans += 3;
		}
		cout<<ans<<endl;
	}
	return 0;
}

