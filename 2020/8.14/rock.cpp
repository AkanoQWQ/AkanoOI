#include<bits/stdc++.h>
using namespace std;
int ans,i,j,k,n,money,cache,fm,ji;
int r[2000006][2];
int main(){
	freopen("rock.in","r",stdin);
	freopen("rock.out","w",stdout); 
	cin>>n; 
	for(i = 0;i < 2;i++){
		for(j = 0;j < n;j++){
			cin>>r[j][i];
		}
	} //n 5
	for(i = n-1;i >= 0;i--){
		
		cache = 0;
		ji = 0;
		j = i;
		while(ji < n){
			money += r[j][0];
			money -= r[j][1];
			cache += r[j][0];
			if(money < 0){
				continue;
				cout<<"dabiao"<<endl;
			}
			if(j == n-1){
				j = 0;
			}else{
				j++;
			}
			ji++;
		}
		if(cache >= fm){
			fm = cache;
			ans = i; 
		}
		
	}
	cout<<ans;
	return 0;
}
