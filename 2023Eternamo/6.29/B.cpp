#include<bits/stdc++.h>
using namespace std;
int T;
pair<int,int> a,b,c;
bool tog(int x,int y){
	return (x > 0 && y > 0) || (x < 0 && y < 0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
		int ans = 0;
		if(tog(a.first - b.first,a.first - c.first)){
			ans += min(abs(a.first - b.first),abs(a.first - c.first));
		}
		if(tog(a.second - b.second,a.second - c.second)){
			ans += min(abs(a.second - b.second),abs(a.second - c.second));
		}
		cout<<ans+1<<endl; 
	}
	return 0;
}

