#include<bits/stdc++.h>
using namespace std;
int h,w,d,i,j,k,c,q,l,ans,r[4100][4100],hw,rr;
struct pos{
	int x,y;
}a[90006];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>h>>w>>d;
	hw = h * w;
	for(i = 1;i <= h;i++){
		for(j = 1;j <= w;j++){
			cin>>c;
			a[c].x = i,a[c].y = j;
		}
	}
	for(i = 1;i <= hw;i++){
		for(j = i+1;j <= hw;j++){
			r[i][j] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
			r[j][i] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
		}
	}
	cin>>q;
	while(q--){
		cin>>l>>rr;
		ans = 0;
		while(l < rr){
			ans += r[l][l+2];
			l += 2;
		}
		cout<<ans<<endl;
	}
	return 0;
}

