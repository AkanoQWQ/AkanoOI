#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,bhead,bi/*big I*/,L,R,ans,typeNum,typeValue,tail,cnt,c2;
bool TBU[200611],FOUND;//TYPE_BE_USED
struct bread{
	long long x,y;
}b[200611];
bool comp(bread a,bread b){
	if(a.y != b.y)return a.y > b.y;
	return a.x < b.x;
}
int main(){
	freopen("bread.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>b[i].x>>b[i].y;
	}
	for(bi = 0;bi < k;bi++){
		sort(b,b+n,comp);
		typeValue = ((typeNum+1) * (typeNum+1)) -((typeNum) * (typeNum));
		if(TBU[b[bhead].x] == 0){
			typeNum++;
			ans += b[bhead].y + typeValue;
			TBU[b[bhead].x] = 1;
			bhead++;
		}else{
			tail = bhead,FOUND = 0;
			while(tail < n){
				tail++;
				if(TBU[b[tail].x] == 0 && tail < n){
					FOUND = 1;
					break;	
				}
			}
			if(FOUND == 0){
				ans += b[bhead].y;
				bhead++;
			}else{
				cnt = b[tail].y + typeValue,c2 = b[bhead].y;
				//cout<<"tail:"<<tail<<",cnt:"<<cnt<<",c2:"<<c2<<",tail:"<<tail<<endl; 
				if(c2 >= cnt){
					ans += c2;
					bhead++;
				}else{
					typeNum++;
					ans += cnt;
					TBU[b[tail].x] = 1;
					b[tail].x = b[bhead].x,b[tail].y = b[bhead].y;
					bhead++;
				}
			}
		}
		/*for(i = bhead;i < n;i++){
			cout<<i<<":"<<b[i].x<<" "<<b[i].y<<","<<ans<<"(found:"<<FOUND<<endl;
		}
		cout<<endl<<endl;*/
	}
	cout<<ans; 
	return 0;
}

