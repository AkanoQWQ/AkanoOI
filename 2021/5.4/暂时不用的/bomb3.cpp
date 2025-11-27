#include<bits/stdc++.h>
using namespace std;
int n,a,b,h[100006],i,j,did,ans,atk,minh = 20061108,allhit,total,cache,beat;
int main(){
	freopen("bomb.in","r",stdin);
	//freopen("bomb.out","w",stdout);
	cin>>n>>a>>b;
	for(i = 0;i < n;i++){
		cin>>h[i];
		total += h[i];
		minh = min(minh,h[i]);
	}
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			cache = h[i];
			h[i] = h[j];
			h[j] = cache;
		}
	}
	ans = 0;
	ans += total / (a+(b*n));
	allhit += ans * b;
	if(ans > 1){
		ans -= 2;
	}
	while(1){
		cout<<ans<<endl;
		cout<<(h[beat+1] - h[beat])<<endl;
		for(i = beat;i < n;i++){
			if(h[i] < allhit){
				beat = i;
			}
		}
		did = 0;
		ans += max((h[beat+1] - h[beat]) / (a+(b*n)),1);
		atk = ans;
		allhit += b;
//		cout<<"ans为"<<ans<<"时,"<<endl; 
		for(i = 0;i < n;i++){
			if(h[i] > allhit){
				if((h[i]-allhit) % (a-b) == 0){
					atk -= ((h[i]-allhit)/(a-b));
//					cout<<"attack减少了"<<((h[i]-allhit)/a)<<",";
				}else{
					atk -= (((h[i]-allhit)/(a-b))+1);
//					cout<<"attack(不可整除)减少了"<<(((h[i]-allhit)/a)+1)<<",";
				}
			}
			if(atk < 0){
//				cout<<"atk<0了"<<endl;
				did = 1;
				break;
			}
		}
		if(!did){
//			cout<<"第"<<ans<<"个攻击时,atk:"<<atk<<",allhit:"<<allhit<<endl;
			if(atk >= 0){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}

