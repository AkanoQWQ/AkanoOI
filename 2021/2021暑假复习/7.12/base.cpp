#include<bits/stdc++.h>
using namespace std;
int n,i,k,ck,wei,include_seven,obj,cck,cache,ans;
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	for(k = 1;k <= n;k++){
		cck = 0;
		ck = k;
		include_seven = 0;
		while(ck > 0){
			wei = ck%10;
			if(wei == 7){
				include_seven = 1;
				break;
			}
			ck /= 10;
		}
		obj = 1,ck = k,wei = 1;
		if(include_seven == 1){
			//cout<<k<<"被pass了";
			continue;
		}
		while(obj <= ck){
			obj *= 8;
			wei *= 10;
		}
		if(obj >= 8){
			obj /= 8;
			wei /= 10;
		}
		while(ck > 0){
			if(ck >= obj){
				cache = ck / obj;
				cck += wei * cache;
				ck -= obj * cache;
			}
			obj /= 8;
			wei /= 10;
		}
		//cout<<k<<"被转换为了"<<cck<<endl;   //k 被转为-> cck(八进制)
		while(cck > 0){
			wei = cck%10;
			if(wei == 7){
				include_seven = 1;
				break;
			}
			cck /= 10;
		}
		if(include_seven == 1){
		//	cout<<k<<"被pass了";
			continue;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}//2834
//

