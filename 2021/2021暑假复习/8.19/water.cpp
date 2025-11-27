#include<bits/stdc++.h>
using namespace std;
int n,h[106],i,j,k,ans,JIAN;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>h[i];
	}
	i = 0;
	while(i < n){
		//cout<<i<<endl;
		JIAN = 0;
		for(j = i;j < n;j++){
			if(h[j] <= 0)break;
		}
		for(k = i;k < j;k++){
			JIAN = 1;
			//cout<<"h["<<k<<"]--"<<endl;
			h[k]--;
		}
		if(JIAN)ans++;
		if(JIAN == 0)i++;
	}
	cout<<ans;
	return 0;
}

