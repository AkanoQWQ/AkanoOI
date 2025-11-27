#include<bits/stdc++.h>
using namespace std;//ÖÚÊý 
int i,j,n,a[2006],m_ax = -1,ans,cache;
int main(){
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cache;
		a[cache]++;
		if(a[cache] > (n/2)+1){
			cout<<cache<<endl;
			break;
			return 0;
		}
	}
	for(i = 0;i < 2006;i++){
		if(a[i] > m_ax){
			m_ax = a[i];
			ans = i;
		}
	}
	cout<<ans;
	return 0;
}
