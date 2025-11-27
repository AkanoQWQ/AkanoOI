#include<bits/stdc++.h>
using namespace std;
struct num{
	int a,b;
}n[200611];
int x,y,i,j,wei,tail,c[200611],cache,k;
bool comp(num a,num b){
	if(a.b != b.b){
		return a.b < b.b;
	}else{
		return a.a < b.a;
	}
}
int main(){
	freopen("ssort.in","r",stdin);
	freopen("ssort.out","w",stdout);
	cin>>x>>y;
	for(i = 0;i <= y - x;i++){
		memset(c,0,sizeof(c));
		wei = 1,tail = 0;
		n[j].a = i+x;
		cache = i+x;
		while(cache > 0){
			c[tail] = cache % 10;
			cache /= 10;
			tail++;
		}
		while(tail >= 0){
			tail--;
			n[i].b += wei * c[tail];
			wei *= 10;
		}
		//cout<<i<<":"<<n[i].b<<endl;
		j++;
	}
	k = y-x+1;
	sort(n,n+k,comp);
	for(i = 0;i < y-x+1;i++){
		cout<<n[i].a<<endl;
	} 
	return 0;
}

