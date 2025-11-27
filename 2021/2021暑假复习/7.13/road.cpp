#include<bits/stdc++.h>
using namespace std;
long long money,i,j,n,need,has_built[100006],cnt,build_obj;
struct city{
	long long x,y;
}cities[100006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cities[i].x>>cities[i].y;
	}
	for(i = 0;i < n;i++){
		if(has_built[i] == 1)continue;
		need = 999999999;
		for(j = 0;j < n;j++){
			if(i == j)continue;
			cnt = min(abs(cities[i].x-cities[j].x),abs(cities[i].y-cities[j].y));
			if(cnt <= need){
				need = cnt;
				build_obj = j;
			}
			if(need == 0){
				break;
			}
		}
		has_built[i] = 1;
		has_built[build_obj] = 1;
		money += need;
	}
		
	cout<<money;
	return 0;
}

