#include<bits/stdc++.h>
using namespace std;
long long money,i,j,n,has_built[100006],buildnum = 1;
struct city{
	long long x,y;
}cs[100006];
long long build(long long th,long long cantbuild){
	buildnum++;
	has_built[th] = 1;
	int need = 999999999,cnt,i,build_obj;
	for(i = 0;i < n;i++){
		if(has_built[i] == 1 || i == cantbuild)continue;
		cnt = min(abs(cs[th].x-cs[i].x),abs(cs[th].y-cs[i].y));
			if(cnt <= need){
				need = cnt;
				build_obj = i;
				cout<<i<<"   ";
			}
			if(need == 0){
				break;
			}
	}
	money += need;
	cout<<"修了"<<th<<"与"<<build_obj<<"之间的路,花费"<<need<<"元"<<endl;
	if(buildnum >= n){
		return 0;
	}
	build(build_obj,th);
}
int main(){
	freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cs[i].x>>cs[i].y;
	}
	build(0,0);
	cout<<money;
	return 0;
}

