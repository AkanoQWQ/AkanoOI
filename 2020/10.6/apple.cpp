#include<bits/stdc++.h>
using namespace std;//remember long long 
struct app{
	int d/*delicious*/;
	int v/*value*/;//1红2绿3无色 
}apples[300006],cache;
namespace stb{
	void mycin(int b[],int n){
		for(int i = 0;i < n;i++){
			cin>>b[i];
		}
	}
	void smycin(app b[],int n,int vv,int k){
		for(int i = k;i < n;i++){
			cin>>b[i].d;
			b[i].v = vv;
		}
	}	
}//常用数据库  
int x,y,a,b,c,i,j,k,abc,t;
long long ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>x>>y>>a>>b>>c;
	stb::smycin(apples,a,1,0);
	stb::smycin(apples,a+b,2,a);
	stb::smycin(apples,a+b+c,3,a+b);
	abc = a + b + c;
	for(i = 0;i < abc;i++){
		for(j = i;j < abc;j++){
			if(apples[i].d < apples[j].d){
				cache = apples[i];
				apples[i] = apples[j];
				apples[j] = cache;
			}
		}
	}
	for(i = 0;i < abc;i++){
		if(apples[i].v == 1 && x != 0){
			x--;
			ans += apples[i].d;
		}
		if(apples[i].v == 2 && y != 0){
			y--;
			ans += apples[i].d;
		}
		if(apples[i].v == 3 && t != c){
			t++;
			ans += apples[i].d;
		}
		if(t == x + y)break;
	}
	cout<<ans;
	return 0;
}
