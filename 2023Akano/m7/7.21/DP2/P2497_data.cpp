#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
const int MAXX = 2e4;
const int MAXR = 1e4;
const int MAXV = 2006 + 1018 + 1108;
const int MAXN = 2e4 + 1018 + 1108;
Rander randerx = Rander(1,MAXX);
Rander randerr = Rander(1,MAXR);
Rander randerv = Rander(1,MAXV);
int n = 1e4,m = MAXX;
struct Node{
	double a,b,c;
}node[MAXN];
bool Cmp(Node na,Node nb){
	if(na.a != nb.a)return na.a < nb.a;
	if(na.b != nb.b)return na.b < nb.b;
	return na.c < nb.c;
}
bool HV[MAXX + 100];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2497.in","w",stdout);
	for(int i = 1;i <= n;i++){
		node[i].a = randerx();
		while(HV[int(node[i].a)])node[i].a = randerx();
		HV[int(node[i].a)] = true;
		node[i].b = randerr();
		node[i].c = randerv();
	}
	sort(node + 1,node + n + 1,Cmp);
	m = node[n].a + 1;
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		cout<<node[i].a<<" "<<node[i].b<<" "<<node[i].c<<endl;
	}
	return 0;
}

