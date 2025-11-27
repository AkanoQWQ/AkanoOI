#include<bits/stdc++.h>
using namespace std;
int n,i,cha;
int que[106];
bool last;
int main(){
	freopen("jum.in","r",stdin);
	freopen("jum.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>que[i];
	}
	cin>>cha;
	for(i = 0;i < n;i++){
		if(i != cha-1){
			if(last){
				cout<<que[i-1]<<" ";
			}else{
				cout<<que[i]<<" ";
			}
		}else{
			cout<<que[n-1]<<" ";
			last = 1;
		}
	} 
	return 0;
}
