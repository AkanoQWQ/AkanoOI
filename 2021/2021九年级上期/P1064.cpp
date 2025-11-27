#include<bits/stdc++.h>
using namespace std;
int w,n,p[206],i,j,ans,c,nums;

int main(){
	//freopen("P1064.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>w>>n;
	for(i = 0;i < n;i++){
		cin>>c;
		p[c]++;
	}
	for(i = 200;i >= 3;i--){
		while(p[i] > 0){
			p[i]--;
			for(j = (w-i);j >= 3;j--){
				if(p[j] > 0){
					p[j]--;
					break;
				}
			}
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

