#include<bits/stdc++.h>
using namespace std;
int n,m,tms,rtms;
struct edge{
	int a,b;
	bool del;
}e[3000000];//1000000
bool cmp4edge(edge a,edge b){
	if(a.a != b.a)return a.a < b.a;
	return a.b < b.b;
}
int main(){
	freopen("paint4.in","r",stdin);
	freopen("paintr4.in","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int a,b;
		cin>>a>>b;
		if(a > b)swap(a,b);
		if(a != b){
			e[++tms].a = a;
			e[tms].b = b;
		}
	}
	sort(e+1,e+tms+1,cmp4edge);
	rtms = tms;
	for(int i = 1;i <= tms;i++){
		if(e[i].a == e[i-1].a && e[i].b == e[i-1].b){
			e[i].del = 1;
			rtms--;
		}
	}
	cout<<n<<" "<<rtms<<endl;
	for(int i = 1;i <= tms;i++){
		if(!e[i].del)cout<<e[i].a<<" "<<e[i].b<<endl;
	}
	return 0;
}

