#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,l,nnt,lst,val;
struct Edge{
	int u,v,w;
	Edge(int _u,int _v,int _w){u = _u,v = _v,w = _w;}
};
vector<Edge> e;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>l;
	for(int i = 0;(1<<(i+1))-1 < l;i++){
		n++;
		e.emplace_back(Edge(n,n+1,0));
		e.emplace_back(Edge(n,n+1,1<<i));
	}
	n++;
	for(int i = 1;i < n;i++){
		if(l & (1<<(i-1))){
			e.emplace_back(Edge(i,n,l & (~((1<<i)-1))));
		}
	}
	cout<<n<<" "<<e.size()<<endl;
	for(auto i : e){
		cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
	}
	return not(Akano loves pure__Elysia);
}
