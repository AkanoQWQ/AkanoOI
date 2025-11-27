#include<bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
const int MN = 20061;
int fa[MN],a,b,i,j,n,m,q,c;
int GetFa(int s){
	if(fa[s] == s)return s;
	fa[s] = GetFa(fa[s]);
	return fa[s];
}
void Connet(int a,int b){
	a = GetFa(a);
	b = GetFa(b);
	if(a != b)fa[a] = b;//第一次错了,查出来问题在这里 
	return ;
}
int main(){
	//freopen("P1556.in","r",stdin);
	//freopen(".out","w",stdout);
	//在课外班学的方法,没有想到怎么用今天学的方法做 编译错误x2 ... 时间超限(7ms)... 
	scanf("%d%d",&n,&m);
	//cin>>n>>m;
	for(i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(i = 0;i < m;i++){
		scanf("%d%d",&a,&b);
		if(a < b){
			c = a,a = b,b = c;
		}
		Connet(a,b);
	}
	scanf("%d",&q);
	for(i = 0;i < q;i++){
		cin>>a>>b;
		if(GetFa(a) == GetFa(b)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}

