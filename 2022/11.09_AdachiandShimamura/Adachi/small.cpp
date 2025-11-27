#include<bits/stdc++.h>
using namespace std;
int ink,s,ans;
__int128 k;
int main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	cin>>ink;
	k = ink;
	ans = 0x7fffffff;
	for(int j = 1;j <= 1000000;j++){
		s = 0;
		__int128 ck = k * j;
		while(ck){
			s += (ck % 10);
			ck /= 10;
		}
		ans = min(ans,s);
	}
	cout<<ans;
	return 0;
}
