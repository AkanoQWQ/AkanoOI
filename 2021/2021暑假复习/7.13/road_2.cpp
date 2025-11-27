#include<bits/stdc++.h>
using namespace std;
struct city{
	long long x,y,next;
}cs[100006];
long long n,i,j,need,cnt,build_obj,money,result;
bool se(long long zb,long long obj,long long cantdo){
	cout<<"正在"<<zb<<"中搜索"<<obj<<",next为"<<cs[zb].next<<endl;//1 0
	if(zb == cantdo)return 0;
	if(cs[zb].next == obj){
		return 1;
	}
	if(cs[zb].next == -1){
		return 0;
	}
	return se(cs[zb].next,j,cantdo);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i = 0;i <= n+10;i++){
		cs[i].next = -1;
	}
	for(i = 0;i < n;i++){
		cin>>cs[i].x>>cs[i].y;
	}
	for(i = 0;i < n;i++){
		need = 999999999;
		for(j = 0;j < n;j++){
			if(i == j)continue;
			result = se(i,j,i);
			if(result == 1)break;
			result = se(j,i,j);
			if(result == 1)break;
			cnt = min(abs(cs[i].x-cs[j].x),abs(cs[i].y-cs[j].y));
			if(cnt <= need){
				need = cnt;
				build_obj = j;
			}
			if(need == 0){
				break;
			}
		}
		money += need;
		cout<<"修了"<<i<<"与"<<build_obj<<"之间的路"<<endl;
		cs[i].next = build_obj;
	}
	cout<<money;
	return 0;
}

