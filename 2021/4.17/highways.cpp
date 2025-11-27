#include<bits/stdc++.h>
using namespace std;
int n,i,j,_Map[506][506];
int XLDL[506]/*修路队列*/,YS[506]/*已修*/,YStail,tail,cans,ans,dodone/*已做完*/;
struct smap{
	int a,b,m;
}smap[506],cache;
int aans;
int main(){
	freopen("highways.in","r",stdin);
	freopen("highways.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			cin>>_Map[i][j];
			smap[tail].a = i;
			smap[tail].b = j;
			smap[tail].m = _Map[i][j];
			aans = max(aans,_Map[i][j]);
		}
	}
	cout<<aans;
	return 0;
}

