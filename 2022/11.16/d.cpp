#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll t,n,m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll five = 0,two = 0,obj = n,maxo = n*m;
		while(n%2==0){
			two++;
			n /= 2;
		}
		while(n%5==0){
			five++;
			n /= 5;
		}
		while(two < five && obj*2 <= maxo){
			obj *= 2;
			two++;
		}
		while(two > five && obj*5 <= maxo){
			obj *= 5;
			five++;
		}
		while(obj*10 <= maxo){
			obj *= 10;
			five++;
			two++;
		}
		ll l = 1,r = min(m+2,(maxo/obj)+2),ret = 1;
		while(l <= r){
			ll mid = (l + r) >> 1;
			ll comp = obj*mid;
			if(comp <= maxo){
				ret = mid;
				l = mid + 1;
			}else{
				r = mid-1;
			}
		}
		obj *= ret;
		cout<<obj<<endl;
	}
	return 0;
}
//咱知道做不做出来某人肯定都要嘲讽,那咱就做咯...
//留句话免得某人继续阴阳怪气 
