#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t,n,k,_3[66],hv[66],cnt; //_3 39
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	_3[0] = 1;
	for(int i = 1;i <= 60;i++){
		_3[i] = _3[i-1] * 3;
	}
	while(t--){
		cin>>n>>k;
		cnt = 0;
		for(int i = 39;i >= 0;i--){
			hv[i] = n / _3[i];
			cnt += hv[i];
			n %= _3[i];
		}
		if(cnt > k){
			cout<<"No"<<endl;
		}else if(cnt == k){
			cout<<"Yes"<<endl;
		}else if((cnt - k) % 2 != 0){
			cout<<"No"<<endl;
		}else{
			for(int i = 39;i >= 1;i--){
				const ll obj = k - cnt;
				const ll decr = min(obj / 2,hv[i]);
				hv[i] -= decr,hv[i-1] += decr * 3;
				cnt += decr * 2;
			}
			if(cnt == k){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
		
	}
	return 0;
}

