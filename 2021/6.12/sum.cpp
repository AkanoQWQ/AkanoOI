#include<bits/stdc++.h>
using namespace std;
int a,b,bb,i,j,ans,d = 0,num[200611];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>a>>b;
	bb = b;
	for(i = 1;i <= 1001;i++){
		for(j = 1;j <= i;j++){
			if(bb < 0){
				break;
			}
			bb--;	
			num[d] = i;
			d++;
		}
	}
	//for(i = 0;i < b;i++){
	//	cout<<num[i]<<" ";
	//}
	for(i = a-1;i < b;i++){
		ans += num[i];
	}
	cout<<ans;
	return 0;
}

