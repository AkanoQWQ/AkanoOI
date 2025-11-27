#include<bits/stdc++.h>
using namespace std;
int i,n,ans,mmax,ttime;
int m[100001][2];
priority_queue <int> mice; 
int main(){
	freopen("mouse.in","r",stdin);
	//freopen("mouse.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>m[i][1];
	}
	for(i = 0;i < n;i++){
		cin>>m[i][0];
			if(m[i][0] > mmax){
			mmax = m[i][0];
		}
	}
	cout<<mmax<<endl;
	
	for(i = 0;i < n;i++){
		if(mice.size() < mmax){
			if(m[i][0] > ttime){
				mice.push(-m[i][0]);
			}else{
				mice.push(-m[i][0]);
				mice.pop();
			}
		}else{
			mice.push(-m[i][0]);
			mice.pop();
		}
	}
	for(i = 0;i < mmax&&i < n;i++){
		ans -= mice.top();
		cout<<mice.top()<<"   ";
		mice.pop();
	}
	cout<<ans;
	return 0;
}
