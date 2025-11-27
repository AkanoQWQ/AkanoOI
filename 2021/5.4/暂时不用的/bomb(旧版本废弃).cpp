#include<bits/stdc++.h>
using namespace std;
int n,a,b,h[100006],i,did,ans,atk,minh = 20061108,allhit;
int main(){
	freopen("bomb.in","r",stdin);
	//freopen("bomb.out","w",stdout);
	cin>>n>>a>>b;
	for(i = 0;i < n;i++){
		cin>>h[i];
		minh = min(minh,h[i]);
	}
	ans = 0;
	if(minh > b){
		ans += (minh/b);
		allhit += (minh/b) * b;
	}
	if(ans > 1){
		ans -= 2;
	}
	while(1){
		did = 0;
		ans++;
		atk = ans;
		allhit += b;
//		cout<<"ans为"<<ans<<"时,"; 
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

