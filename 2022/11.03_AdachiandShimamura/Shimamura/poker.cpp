#include<bits/stdc++.h>
using namespace std;
int a[2006],cnt,c2,b[2006];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i = 1;i <= 20;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	while(1){
		bool fd = 0;
		for(int i = 1;i <= 20;i++){
			if(a[i-1] == 1){
				a[i-1] = !a[i-1];
				a[i] = !a[i];
				a[i+1] = !a[i+1];
				fd = 1;
				break;
			}
		}
		if(!fd)break;
		cnt++;
	}
	while(1){
		bool fd = 0;
		for(int i = 20;i >= 1;i--){
			if(b[i-1] == 1){
				b[i-1] = !b[i-1];
				b[i] = !b[i];
				b[i+1] = !b[i+1];
				fd = 1;
				break;
			}
		}
		if(!fd)break;
		c2++;
	}
	cout<<min(cnt,c2);
	return 0;
}
