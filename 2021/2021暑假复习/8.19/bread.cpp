#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,bhead,bi/*big I*/,L,R,ans,typeNum,typeValue,tail,cnt,c2;
int TBU[200611],FOUND;//TYPE_BE_USED
struct bread{
	long long x,y,value;
}b[200611];
bool comp(bread a,bread b){
	if(a.y != b.y)return a.y < b.y;
	return a.x < b.x;
}
bool comp2(bread a,bread b){
	if(a.value != b.value)return a.value < b.value;
	return a.y > b.y;
}
int main(){
	freopen("bread.in","r",stdin);
	freopen("bread.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>b[i].x>>b[i].y;
	}
	for(i = 0;i < n;i++){
		ans += b[i].y;
		if(TBU[b[i].x] == 0){
			cnt++;
		}
		TBU[b[i].x]++;
	}
	//cout<<TBU[2]<<"   ";
	ans += (cnt * cnt);
	for(bi = 0;bi < (n-k);bi++){
		typeValue = cnt*cnt - (cnt-1)*(cnt-1);
		for(i = bhead;i < n;i++){
			b[i].value = b[i].y;
			if(TBU[b[i].x] == 1){
				b[i].value += typeValue;
			}
		}
		sort(b,b+n,comp2);
		//cout<<TBU[2]<<" :";
		//cout<<"ÉáÆúÁË"<<b[bhead].x<<" "<<b[bhead].y<<",ËðÊ§"<<b[bhead].value<<"("<<typeValue<<endl;
		ans -= b[bhead].value;
		TBU[b[bhead].x]--;
		if(TBU[b[bhead].x] == 0)cnt--;
		b[bhead].y = 0,b[bhead].value = 0;
		bhead++;
	}
	cout<<ans; 
	return 0;
}

