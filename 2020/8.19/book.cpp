#include<bits/stdc++.h>
using namespace std;
int hatime/*苟利国家生死以，岂因祸福避趋之*/;//蛤time 
int n,m,ans,i;
int a[200006],b[200006];
int du(int intime,int azj,int bzj,int inans){
	int aa,bb;
	if(intime < a[azj] && intime < b[bzj]){
		return inans;
	}
	if(intime >= a[azj]&&azj < n){
		aa = du(intime-a[azj],azj+1,bzj,inans+1);
	}
	if(intime >= b[bzj]&&bzj < m){
		bb = du(intime-b[bzj],azj,bzj+1,inans+1);
	}
	if(aa > bb){
		return aa;
	}else{
		return bb;
	}
	return inans;
}
int main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	cin>>n>>m>>hatime;//time即k                
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){
		cin>>b[i];
	}
	ans = du(hatime,0,0,0);
	cout<<ans;
	return 0;
}
