#include<bits/stdc++.h>
using namespace std;
int i,n,ans,sto[200006],r,j,end,k;
char cache;
int main(){
	freopen("alter.in","r",stdin);
	freopen("alter.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cache;
		if(cache == 'W'){
			sto[i] = 1;
		}else{
			sto[i] = 0;
		}
	}
	i = 0;
	while(i < n){
		end = 1;
		if(sto[i]){
			j = n-1;
			while(j > i){
				if(sto[j] == 0){
					end = 0;
					break;
				}
				j--;
			}
			//j = n-1;
			if(end == 0){
				if(!sto[j] && j > i){
					ans++;
					sto[j] = 1;
					sto[i] = 0;
				}
			}
		}
		i++;
	}
	i = n-1;
	while(i >= 0){
		if(!sto[i]){
			r = 1;
		}
		if(r && sto[i]){
			ans++;
		}
		i--;
	}
	cout<<ans;
	return 0;
}
