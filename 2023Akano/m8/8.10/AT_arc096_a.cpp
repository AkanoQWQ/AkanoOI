#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>x>>y;
	if(2 * c < a + b){
		int xy = min(x,y);
		ans += xy * 2 * c;
		x -= xy,y -= xy;
	}
	if(2 * c < a){
		ans += x * 2 * c;
		x = 0;
	}
	if(2 * c < b){
		ans += y * 2 * c;
		y = 0;
	}
	ans += x * a + y * b;
	cout<<ans;
	return 0;
}
