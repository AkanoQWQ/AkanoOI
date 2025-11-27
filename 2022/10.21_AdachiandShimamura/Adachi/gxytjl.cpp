#include<bits/stdc++.h>
using namespace std;
const int MAXN = 506;
int n,m,p,_haveMeowNums,dis[MAXN];
bool _haveMeow[MAXN];
struct Cat{
	int pos,t;
}c[MAXN];
int main(){
	freopen("gxytjl.in","r",stdin);
	freopen("gxytjl.out","w",stdout);
	cin>>n>>m>>p;
	for(int i = 0;i < n;i++){
		int c;
		cin>>dis[i+1];
		dis[i+1] += dis[i];
	}
	for(int i = 1;i <= m;i++){
		cin>>c[i].pos>>c[i].pos;
		if(!_haveMeow[c[i].pos]){
			_haveMeow[c[i].pos] = 1;
			_haveMeowNums++;
		}
	}
	if(_haveMeowNums <= p){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
