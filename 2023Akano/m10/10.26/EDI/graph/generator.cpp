#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
inline void Make(){
	int n = 150,m = 200,c1 = rd(5,10),c2 = rd(12,18);
	cout<<n<<" "<<m<<" "<<c1<<" "<<c2<<endl;
	set<pair<int,int> > e;
	for(int i = 1;i <= m;i++){
		int u = rd(1,n),v = u;
		if(rd(0,1)){
			v = u + c1;
		}else{
			v = u + c2;
		}
		while(v > n || e.find({u,v}) != e.end()){
			u = rd(1,n);
			if(rd(0,1)){
				v = u + c1;
			}else{
				v = u + c2;
			}
		}
		e.insert({u,v});
		cout<<u<<" "<<v<<endl;
	}
	return ;
}
inline void Solve(){
	system("graph.exe");
	return ;
}
int main(){
	MakeData("graph",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
